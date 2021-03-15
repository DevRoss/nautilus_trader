# -------------------------------------------------------------------------------------------------
#  Copyright (C) 2015-2021 Nautech Systems Pty Ltd. All rights reserved.
#  https://nautechsystems.io
#
#  Licensed under the GNU Lesser General Public License Version 3.0 (the "License");
#  You may not use this file except in compliance with the License.
#  You may obtain a copy of the License at https://www.gnu.org/licenses/lgpl-3.0.en.html
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
# -------------------------------------------------------------------------------------------------

import asyncio
import collections
import types


cdef class Queue:
    """
    Provides a high-performance stripped back queue for use with coroutines
    and an event loop.

    If maxsize is less than or equal to zero, the queue size is infinite. If it
    is an integer greater than 0, then "await put()" will block when the
    queue reaches maxsize, until an item is removed by get().

    Unlike the standard library Queue, you can reliably know this Queue's size
    with qsize(), since your single-threaded asyncio application won't be
    interrupted between calling qsize() and doing an operation on the Queue.

    Warnings
    --------
    This queue is not thread-safe and must be called from the same thread as the
    event loop.

    """

    def __init__(self, int maxsize=0):
        """
        Initialize a new instance of the `Queue` class.

        Parameters
        ----------
        maxsize : int
            The maximum capacity of the queue before blocking.

        """

        self.maxsize = maxsize
        self.count = 0

        self._queue = collections.deque()

    cpdef int qsize(self) except *:
        """
        Return the number of items in the queue.

        Returns
        -------
        int

        """
        return self._qsize()

    cpdef bint empty(self) except *:
        """
        Return a value indicating whether the queue is empty.

        Returns
        -------
        bool
            True if the queue is empty, False otherwise.

        """
        return self._empty()

    cpdef bint full(self) except *:
        """
        Return a value indicating whether the queue is full.

        Returns
        -------
        bool
            True if there are maxsize items in the queue.

        Notes
        -----
        If the Queue was initialized with maxsize=0 (the default),
        then full() is never True.

        """
        return self._full()

    async def put(self, item):
        """
        Put an item into the queue.

        If the queue is full, wait until a free slot is available before adding
        item.

        Parameters
        ---------
        item : object
            The item to add to the queue.

        """
        while self._full():
            # Wait for free slot
            await self._sleep0()
            continue

        self._put_nowait(item)

    cpdef void put_nowait(self, item) except *:
        """
        Put an item into the queue without blocking.

        Raises
        ------
        QueueFull
            If no free slot is immediately available.

        """
        self._put_nowait(item)

    async def get(self):
        """
        Remove and return the next item from the queue.

        If the queue is empty, wait until an item is available.

        Returns
        -------
        object

        """
        while self._empty():
            # Wait for item to become available
            await self._sleep0()
            continue

        return self._get_nowait()

    cpdef object get_nowait(self):
        """
        Remove and return an item from the queue.

        Raises
        ------
        QueueEmpty
            If an item is not immediately available.

        """
        return self._get_nowait()

    @types.coroutine
    def _sleep0(self):
        yield  # Skip one event loop run cycle

    cdef inline int _qsize(self) except *:
        return self.count

    cdef inline bint _empty(self) except *:
        return self.count == 0

    cdef inline bint _full(self) except *:
        if self.maxsize <= 0:
            return False
        else:
            return self.count >= self.maxsize

    cdef inline void _put_nowait(self, item) except *:
        if self._full():
            raise asyncio.QueueFull()
        self._queue.append(item)
        self.count += 1

    cdef inline object _get_nowait(self):
        if self.empty():
            raise asyncio.QueueEmpty()
        item = self._queue.popleft()
        self.count -= 1
        return item

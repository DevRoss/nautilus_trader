# -------------------------------------------------------------------------------------------------
#  Copyright (C) 2015-2024 Nautech Systems Pty Ltd. All rights reserved.
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

from cpython.datetime cimport datetime
from cpython.datetime cimport timedelta
from libc.stdint cimport uint8_t
from libc.stdint cimport uint64_t

from nautilus_trader.common.component cimport Clock
from nautilus_trader.common.component cimport Logger
from nautilus_trader.common.component cimport TimeEvent
from nautilus_trader.model.data cimport Bar
from nautilus_trader.model.data cimport BarType
from nautilus_trader.model.data cimport QuoteTick
from nautilus_trader.model.data cimport TradeTick
from nautilus_trader.model.objects cimport Price
from nautilus_trader.model.objects cimport Quantity


cdef class BarBuilder:
    cdef BarType _bar_type

    cdef readonly uint8_t price_precision
    """The price precision for the builders instrument.\n\n:returns: `uint8`"""
    cdef readonly uint8_t size_precision
    """The size precision for the builders instrument.\n\n:returns: `uint8`"""
    cdef readonly bint initialized
    """If the builder is initialized.\n\n:returns: `bool`"""
    cdef readonly uint64_t ts_last
    """UNIX timestamp (nanoseconds) when the builder last updated.\n\n:returns: `uint64_t`"""
    cdef readonly int count
    """The builders current update count.\n\n:returns: `int`"""

    cdef bint _partial_set
    cdef Price _last_close
    cdef Price _open
    cdef Price _high
    cdef Price _low
    cdef Price _close
    cdef Quantity volume

    cpdef void set_partial(self, Bar partial_bar, bint run_once=*)
    cpdef void update(self, Price price, Quantity size, uint64_t ts_event)
    cpdef void reset(self)
    cpdef Bar build_now(self)
    cpdef Bar build(self, uint64_t ts_event, uint64_t ts_init)


cdef class BarAggregator:
    cdef Logger _log
    cdef BarBuilder _builder
    cdef object _handler
    cdef bint _await_partial

    cdef readonly BarType bar_type
    """The aggregators bar type.\n\n:returns: `BarType`"""

    cpdef void handle_quote_tick(self, QuoteTick tick)
    cpdef void handle_trade_tick(self, TradeTick tick)
    cpdef void handle_bar(self, Bar bar)
    cpdef void set_partial(self, Bar partial_bar, bint run_once=*)
    cdef void _apply_update(self, Price price, Quantity size, uint64_t ts_event)
    cdef void _build_now_and_send(self)
    cdef void _build_and_send(self, uint64_t ts_event, uint64_t ts_init)


cdef class TickBarAggregator(BarAggregator):
    pass


cdef class VolumeBarAggregator(BarAggregator):
    pass


cdef class ValueBarAggregator(BarAggregator):
    cdef object _cum_value

    cpdef object get_cumulative_value(self)


cdef class TimeBarAggregator(BarAggregator):
    cdef Clock _clock
    cdef bint _build_on_next_tick
    cdef uint64_t _stored_open_ns
    cdef uint64_t _stored_close_ns
    cdef tuple _cached_update
    cdef str _timer_name
    cdef bint _build_with_no_updates
    cdef bint _timestamp_on_close
    cdef bint _is_left_open

    cdef readonly timedelta interval
    """The aggregators time interval.\n\n:returns: `timedelta`"""
    cdef readonly uint64_t interval_ns
    """The aggregators time interval.\n\n:returns: `uint64_t`"""
    cdef readonly uint64_t next_close_ns
    """The aggregators next closing time.\n\n:returns: `uint64_t`"""

    cpdef datetime get_start_time(self)
    cpdef void stop(self)
    cdef timedelta _get_interval(self)
    cdef uint64_t _get_interval_ns(self)
    cpdef void _set_build_timer(self)
    cpdef void _build_bar(self, TimeEvent event)

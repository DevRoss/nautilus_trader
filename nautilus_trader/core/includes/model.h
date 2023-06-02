/* Generated with cbindgen:0.24.5 */

/* Warning, this file is autogenerated by cbindgen. Don't modify this manually. */

#include <stdint.h>
#include <Python.h>

#define FIXED_PRECISION 9

#define FIXED_SCALAR 1000000000.0

#define MONEY_MAX 9223372036.0

#define MONEY_MIN -9223372036.0

#define PRICE_MAX 9223372036.0

#define PRICE_MIN -9223372036.0

#define QUANTITY_MAX 18446744073.0

#define QUANTITY_MIN 0.0

/**
 * Represents an account type provided by a trading venue or broker.
 */
typedef enum AccountType {
    /**
     * An account type with unleveraged cash assets only.
     */
    CASH = 1,
    /**
     * An account type which facilitates trading on margin, using account assets as collateral.
     */
    MARGIN = 2,
    /**
     * An account type specific to betting markets.
     */
    BETTING = 3,
} AccountType;

typedef enum AggregationSource {
    EXTERNAL = 1,
    INTERNAL = 2,
} AggregationSource;

typedef enum AggressorSide {
    NO_AGGRESSOR = 0,
    BUYER = 1,
    SELLER = 2,
} AggressorSide;

typedef enum AssetClass {
    FX = 1,
    EQUITY = 2,
    COMMODITY = 3,
    METAL = 4,
    ENERGY = 5,
    BOND = 6,
    INDEX = 7,
    CRYPTOCURRENCY = 8,
    SPORTS_BETTING = 9,
} AssetClass;

typedef enum AssetType {
    SPOT = 1,
    SWAP = 2,
    FUTURE = 3,
    FORWARD = 4,
    CFD = 5,
    OPTION = 6,
    WARRANT = 7,
} AssetType;

typedef enum BookAction {
    ADD = 1,
    UPDATE = 2,
    DELETE = 3,
    CLEAR = 4,
} BookAction;

typedef enum BookType {
    /**
     * Top-of-book best bid/offer.
     */
    L1_TBBO = 1,
    /**
     * Market by price.
     */
    L2_MBP = 2,
    /**
     * Market by order.
     */
    L3_MBO = 3,
} BookType;

typedef enum ContingencyType {
    NO_CONTINGENCY = 0,
    OCO = 1,
    OTO = 2,
    OUO = 3,
} ContingencyType;

typedef enum CurrencyType {
    CRYPTO = 1,
    FIAT = 2,
} CurrencyType;

typedef enum DepthType {
    VOLUME = 1,
    EXPOSURE = 2,
} DepthType;

typedef enum InstrumentCloseType {
    END_OF_SESSION = 1,
    CONTRACT_EXPIRED = 2,
} InstrumentCloseType;

typedef enum LiquiditySide {
    NO_LIQUIDITY_SIDE = 0,
    MAKER = 1,
    TAKER = 2,
} LiquiditySide;

typedef enum MarketStatus {
    CLOSED = 1,
    PRE_OPEN = 2,
    OPEN = 3,
    PAUSE = 4,
    PRE_CLOSE = 5,
} MarketStatus;

typedef enum OmsType {
    UNSPECIFIED = 0,
    NETTING = 1,
    HEDGING = 2,
} OmsType;

typedef enum OptionKind {
    CALL = 1,
    PUT = 2,
} OptionKind;

typedef enum OrderSide {
    NO_ORDER_SIDE = 0,
    BUY = 1,
    SELL = 2,
} OrderSide;

typedef enum OrderStatus {
    INITIALIZED = 1,
    DENIED = 2,
    SUBMITTED = 3,
    ACCEPTED = 4,
    REJECTED = 5,
    CANCELED = 6,
    EXPIRED = 7,
    TRIGGERED = 8,
    PENDING_UPDATE = 9,
    PENDING_CANCEL = 10,
    PARTIALLY_FILLED = 11,
    FILLED = 12,
} OrderStatus;

typedef enum OrderType {
    MARKET = 1,
    LIMIT = 2,
    STOP_MARKET = 3,
    STOP_LIMIT = 4,
    MARKET_TO_LIMIT = 5,
    MARKET_IF_TOUCHED = 6,
    LIMIT_IF_TOUCHED = 7,
    TRAILING_STOP_MARKET = 8,
    TRAILING_STOP_LIMIT = 9,
} OrderType;

typedef enum PositionSide {
    NO_POSITION_SIDE = 0,
    FLAT = 1,
    LONG = 2,
    SHORT = 3,
} PositionSide;

typedef enum PriceType {
    BID = 1,
    ASK = 2,
    MID = 3,
    LAST = 4,
} PriceType;

typedef enum TimeInForce {
    GTC = 1,
    IOC = 2,
    FOK = 3,
    GTD = 4,
    DAY = 5,
    AT_THE_OPEN = 6,
    AT_THE_CLOSE = 7,
} TimeInForce;

typedef enum TradingState {
    ACTIVE = 1,
    HALTED = 2,
    REDUCING = 3,
} TradingState;

typedef enum TrailingOffsetType {
    NO_TRAILING_OFFSET = 0,
    PRICE = 1,
    BASIS_POINTS = 2,
    TICKS = 3,
    PRICE_TIER = 4,
} TrailingOffsetType;

typedef enum TriggerType {
    NO_TRIGGER = 0,
    DEFAULT = 1,
    BID_ASK = 2,
    LAST_TRADE = 3,
    DOUBLE_LAST = 4,
    DOUBLE_BID_ASK = 5,
    LAST_OR_BID_ASK = 6,
    MID_POINT = 7,
    MARK_PRICE = 8,
    INDEX_PRICE = 9,
} TriggerType;

typedef struct Arc_String Arc_String;

typedef struct OrderBook OrderBook;

typedef struct String String;

typedef struct Symbol_t {
    struct Arc_String *value;
} Symbol_t;

typedef struct Venue_t {
    struct Arc_String *value;
} Venue_t;

typedef struct InstrumentId_t {
    struct Symbol_t symbol;
    struct Venue_t venue;
} InstrumentId_t;

typedef struct BarSpecification_t {
    uint64_t step;
    uint8_t aggregation;
    enum PriceType price_type;
} BarSpecification_t;

typedef struct BarType_t {
    struct InstrumentId_t instrument_id;
    struct BarSpecification_t spec;
    enum AggregationSource aggregation_source;
} BarType_t;

typedef struct Price_t {
    int64_t raw;
    uint8_t precision;
} Price_t;

typedef struct Quantity_t {
    uint64_t raw;
    uint8_t precision;
} Quantity_t;

typedef struct Bar_t {
    struct BarType_t bar_type;
    struct Price_t open;
    struct Price_t high;
    struct Price_t low;
    struct Price_t close;
    struct Quantity_t volume;
    uint64_t ts_event;
    uint64_t ts_init;
} Bar_t;

/**
 * Represents an order in a book.
 */
typedef struct BookOrder_t {
    enum OrderSide side;
    struct Price_t price;
    struct Quantity_t size;
    uint64_t order_id;
} BookOrder_t;

/**
 * Represents a single change/delta in an order book.
 */
typedef struct OrderBookDelta_t {
    struct InstrumentId_t instrument_id;
    enum BookAction action;
    struct BookOrder_t order;
    uint8_t flags;
    uint64_t sequence;
    uint64_t ts_event;
    uint64_t ts_init;
} OrderBookDelta_t;

typedef struct TraderId_t {
    struct Arc_String *value;
} TraderId_t;

typedef struct StrategyId_t {
    struct Arc_String *value;
} StrategyId_t;

typedef struct ClientOrderId_t {
    struct Arc_String *value;
} ClientOrderId_t;

typedef struct OrderDenied_t {
    struct TraderId_t trader_id;
    struct StrategyId_t strategy_id;
    struct InstrumentId_t instrument_id;
    struct ClientOrderId_t client_order_id;
    struct String *reason;
    UUID4_t event_id;
    uint64_t ts_event;
    uint64_t ts_init;
} OrderDenied_t;

typedef struct AccountId_t {
    struct Arc_String *value;
} AccountId_t;

typedef struct ClientId_t {
    struct Arc_String *value;
} ClientId_t;

typedef struct ComponentId_t {
    struct Arc_String *value;
} ComponentId_t;

typedef struct ExecAlgorithmId_t {
    struct Arc_String *value;
} ExecAlgorithmId_t;

typedef struct OrderListId_t {
    struct Arc_String *value;
} OrderListId_t;

typedef struct PositionId_t {
    struct Arc_String *value;
} PositionId_t;

typedef struct TradeId_t {
    struct Arc_String *value;
} TradeId_t;

typedef struct VenueOrderId_t {
    struct Arc_String *value;
} VenueOrderId_t;

typedef struct OrderBook_API {
    struct OrderBook *_0;
} OrderBook_API;

/**
 * Represents a single quote tick in a financial market.
 */
typedef struct QuoteTick_t {
    struct InstrumentId_t instrument_id;
    struct Price_t bid;
    struct Price_t ask;
    struct Quantity_t bid_size;
    struct Quantity_t ask_size;
    uint64_t ts_event;
    uint64_t ts_init;
} QuoteTick_t;

/**
 * Represents a single trade tick in a financial market.
 */
typedef struct TradeTick_t {
    struct InstrumentId_t instrument_id;
    struct Price_t price;
    struct Quantity_t size;
    enum AggressorSide aggressor_side;
    struct TradeId_t trade_id;
    uint64_t ts_event;
    uint64_t ts_init;
} TradeTick_t;

typedef struct Currency_t {
    struct Arc_String *code;
    uint8_t precision;
    uint16_t iso4217;
    struct Arc_String *name;
    enum CurrencyType currency_type;
} Currency_t;

typedef struct Money_t {
    int64_t raw;
    struct Currency_t currency;
} Money_t;

struct Bar_t bar_new(struct BarType_t bar_type,
                     struct Price_t open,
                     struct Price_t high,
                     struct Price_t low,
                     struct Price_t close,
                     struct Quantity_t volume,
                     uint64_t ts_event,
                     uint64_t ts_init);

struct Bar_t bar_new_from_raw(struct BarType_t bar_type,
                              int64_t open,
                              int64_t high,
                              int64_t low,
                              int64_t close,
                              uint8_t price_prec,
                              uint64_t volume,
                              uint8_t size_prec,
                              uint64_t ts_event,
                              uint64_t ts_init);

struct BookOrder_t book_order_from_raw(enum OrderSide order_side,
                                       int64_t price_raw,
                                       uint8_t price_prec,
                                       uint64_t size_raw,
                                       uint8_t size_prec,
                                       uint64_t order_id);

uint8_t book_order_eq(const struct BookOrder_t *lhs, const struct BookOrder_t *rhs);

uint64_t book_order_hash(const struct BookOrder_t *order);

double book_order_exposure(const struct BookOrder_t *order);

double book_order_signed_size(const struct BookOrder_t *order);

/**
 * Returns a [`BookOrder`] display string as a C string pointer.
 */
const char *book_order_display_to_cstr(const struct BookOrder_t *order);

/**
 * Returns a [`BookOrder`] debug string as a C string pointer.
 */
const char *book_order_debug_to_cstr(const struct BookOrder_t *order);

void orderbook_delta_drop(struct OrderBookDelta_t delta);

struct OrderBookDelta_t orderbook_delta_clone(const struct OrderBookDelta_t *delta);

struct OrderBookDelta_t orderbook_delta_new(struct InstrumentId_t instrument_id,
                                            enum BookAction action,
                                            struct BookOrder_t order,
                                            uint8_t flags,
                                            uint64_t sequence,
                                            uint64_t ts_event,
                                            uint64_t ts_init);

uint8_t orderbook_delta_eq(const struct OrderBookDelta_t *lhs, const struct OrderBookDelta_t *rhs);

uint64_t orderbook_delta_hash(const struct OrderBookDelta_t *delta);

const char *account_type_to_cstr(enum AccountType value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum AccountType account_type_from_cstr(const char *ptr);

const char *aggregation_source_to_cstr(enum AggregationSource value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum AggregationSource aggregation_source_from_cstr(const char *ptr);

const char *aggressor_side_to_cstr(enum AggressorSide value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum AggressorSide aggressor_side_from_cstr(const char *ptr);

const char *asset_class_to_cstr(enum AssetClass value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum AssetClass asset_class_from_cstr(const char *ptr);

const char *asset_type_to_cstr(enum AssetType value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum AssetType asset_type_from_cstr(const char *ptr);

const char *bar_aggregation_to_cstr(uint8_t value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
uint8_t bar_aggregation_from_cstr(const char *ptr);

const char *book_action_to_cstr(enum BookAction value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum BookAction book_action_from_cstr(const char *ptr);

const char *book_type_to_cstr(enum BookType value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum BookType book_type_from_cstr(const char *ptr);

const char *contingency_type_to_cstr(enum ContingencyType value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum ContingencyType contingency_type_from_cstr(const char *ptr);

const char *currency_type_to_cstr(enum CurrencyType value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum CurrencyType currency_type_from_cstr(const char *ptr);

const char *depth_type_to_cstr(enum DepthType value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum InstrumentCloseType instrument_close_type_from_cstr(const char *ptr);

const char *instrument_close_type_to_cstr(enum InstrumentCloseType value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum DepthType depth_type_from_cstr(const char *ptr);

const char *liquidity_side_to_cstr(enum LiquiditySide value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum LiquiditySide liquidity_side_from_cstr(const char *ptr);

const char *market_status_to_cstr(enum MarketStatus value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum MarketStatus market_status_from_cstr(const char *ptr);

const char *oms_type_to_cstr(enum OmsType value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum OmsType oms_type_from_cstr(const char *ptr);

const char *option_kind_to_cstr(enum OptionKind value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum OptionKind option_kind_from_cstr(const char *ptr);

const char *order_side_to_cstr(enum OrderSide value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum OrderSide order_side_from_cstr(const char *ptr);

const char *order_status_to_cstr(enum OrderStatus value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum OrderStatus order_status_from_cstr(const char *ptr);

const char *order_type_to_cstr(enum OrderType value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum OrderType order_type_from_cstr(const char *ptr);

const char *position_side_to_cstr(enum PositionSide value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum PositionSide position_side_from_cstr(const char *ptr);

const char *price_type_to_cstr(enum PriceType value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum PriceType price_type_from_cstr(const char *ptr);

const char *time_in_force_to_cstr(enum TimeInForce value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum TimeInForce time_in_force_from_cstr(const char *ptr);

const char *trading_state_to_cstr(enum TradingState value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum TradingState trading_state_from_cstr(const char *ptr);

const char *trailing_offset_type_to_cstr(enum TrailingOffsetType value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum TrailingOffsetType trailing_offset_type_from_cstr(const char *ptr);

const char *trigger_type_to_cstr(enum TriggerType value);

/**
 * Returns an enum from a Python string.
 *
 * # Safety
 * - Assumes `ptr` is a valid C string pointer.
 */
enum TriggerType trigger_type_from_cstr(const char *ptr);

/**
 * Returns a Nautilus identifier from a C string pointer.
 *
 * # Safety
 *
 * - Assumes `ptr` is a valid C string pointer.
 */
struct OrderDenied_t order_denied_new(struct TraderId_t trader_id,
                                      struct StrategyId_t strategy_id,
                                      struct InstrumentId_t instrument_id,
                                      struct ClientOrderId_t client_order_id,
                                      const char *reason_ptr,
                                      UUID4_t event_id,
                                      uint64_t ts_event,
                                      uint64_t ts_init);

/**
 * Frees the memory for the given `account_id` by dropping.
 */
void order_denied_drop(struct OrderDenied_t event);

struct OrderDenied_t order_denied_clone(const struct OrderDenied_t *event);

const char *order_denied_reason_to_cstr(const struct OrderDenied_t *event);

/**
 * Returns a Nautilus identifier from a C string pointer.
 *
 * # Safety
 *
 * - Assumes `ptr` is a valid C string pointer.
 */
struct AccountId_t account_id_new(const char *ptr);

struct AccountId_t account_id_clone(const struct AccountId_t *account_id);

/**
 * Frees the memory for the given `account_id` by dropping.
 */
void account_id_drop(struct AccountId_t account_id);

/**
 * Returns an [`AccountId`] as a C string pointer.
 */
const char *account_id_to_cstr(const struct AccountId_t *account_id);

uint8_t account_id_eq(const struct AccountId_t *lhs, const struct AccountId_t *rhs);

uint64_t account_id_hash(const struct AccountId_t *account_id);

/**
 * Returns a Nautilus identifier from C string pointer.
 *
 * # Safety
 *
 * - Assumes `ptr` is a valid C string pointer.
 */
struct ClientId_t client_id_new(const char *ptr);

struct ClientId_t client_id_clone(const struct ClientId_t *client_id);

/**
 * Frees the memory for the given `client_id` by dropping.
 */
void client_id_drop(struct ClientId_t client_id);

/**
 * Returns a [`ClientId`] identifier as a C string pointer.
 */
const char *client_id_to_cstr(const struct ClientId_t *client_id);

uint8_t client_id_eq(const struct ClientId_t *lhs, const struct ClientId_t *rhs);

uint64_t client_id_hash(const struct ClientId_t *client_id);

/**
 * Returns a Nautilus identifier from a C string pointer.
 *
 * # Safety
 *
 * - Assumes `ptr` is a valid C string pointer.
 */
struct ClientOrderId_t client_order_id_new(const char *ptr);

struct ClientOrderId_t client_order_id_clone(const struct ClientOrderId_t *client_order_id);

/**
 * Frees the memory for the given `client_order_id` by dropping.
 */
void client_order_id_drop(struct ClientOrderId_t client_order_id);

/**
 * Returns a [`ClientOrderId`] as a C string pointer.
 */
const char *client_order_id_to_cstr(const struct ClientOrderId_t *client_order_id);

uint8_t client_order_id_eq(const struct ClientOrderId_t *lhs, const struct ClientOrderId_t *rhs);

uint64_t client_order_id_hash(const struct ClientOrderId_t *client_order_id);

/**
 * Returns a Nautilus identifier from a C string pointer.
 *
 * # Safety
 *
 * - Assumes `ptr` is a valid C string pointer.
 */
struct ComponentId_t component_id_new(const char *ptr);

struct ComponentId_t component_id_clone(const struct ComponentId_t *component_id);

/**
 * Frees the memory for the given `component_id` by dropping.
 */
void component_id_drop(struct ComponentId_t component_id);

/**
 * Returns a [`ComponentId`] identifier as a C string pointer.
 */
const char *component_id_to_cstr(const struct ComponentId_t *component_id);

uint8_t component_id_eq(const struct ComponentId_t *lhs, const struct ComponentId_t *rhs);

uint64_t component_id_hash(const struct ComponentId_t *component_id);

/**
 * Returns a Nautilus identifier from a C string pointer.
 *
 * # Safety
 *
 * - Assumes `ptr` is a valid C string pointer.
 */
struct ExecAlgorithmId_t exec_algorithm_id_new(const char *ptr);

struct ExecAlgorithmId_t exec_algorithm_id_clone(const struct ExecAlgorithmId_t *exec_algorithm_id);

/**
 * Frees the memory for the given `exec_algorithm_id` by dropping.
 */
void exec_algorithm_id_drop(struct ExecAlgorithmId_t exec_algorithm_id);

/**
 * Returns an [`ExecAlgorithmId`] identifier as a C string pointer.
 */
const char *exec_algorithm_id_to_cstr(const struct ExecAlgorithmId_t *exec_algorithm_id);

uint8_t exec_algorithm_id_eq(const struct ExecAlgorithmId_t *lhs,
                             const struct ExecAlgorithmId_t *rhs);

uint64_t exec_algorithm_id_hash(const struct ExecAlgorithmId_t *exec_algorithm_id);

struct InstrumentId_t instrument_id_new(const struct Symbol_t *symbol, const struct Venue_t *venue);

/**
 * Returns a Nautilus identifier from a C string pointer.
 *
 * # Safety
 *
 * - Assumes `ptr` is a valid C string pointer.
 */
struct InstrumentId_t instrument_id_new_from_cstr(const char *ptr);

struct InstrumentId_t instrument_id_clone(const struct InstrumentId_t *instrument_id);

/**
 * Frees the memory for the given `instrument_id` by dropping.
 */
void instrument_id_drop(struct InstrumentId_t instrument_id);

/**
 * Returns an [`InstrumentId`] as a C string pointer.
 */
const char *instrument_id_to_cstr(const struct InstrumentId_t *instrument_id);

uint8_t instrument_id_eq(const struct InstrumentId_t *lhs, const struct InstrumentId_t *rhs);

uint64_t instrument_id_hash(const struct InstrumentId_t *instrument_id);

/**
 * Returns a Nautilus identifier from a C string pointer.
 *
 * # Safety
 *
 * - Assumes `ptr` is a valid C string pointer.
 */
struct OrderListId_t order_list_id_new(const char *ptr);

struct OrderListId_t order_list_id_clone(const struct OrderListId_t *order_list_id);

/**
 * Frees the memory for the given `order_list_id` by dropping.
 */
void order_list_id_drop(struct OrderListId_t order_list_id);

/**
 * Returns an [`OrderListId`] as a C string pointer.
 */
const char *order_list_id_to_cstr(const struct OrderListId_t *order_list_id);

uint8_t order_list_id_eq(const struct OrderListId_t *lhs, const struct OrderListId_t *rhs);

uint64_t order_list_id_hash(const struct OrderListId_t *order_list_id);

/**
 * Returns a Nautilus identifier from a C string pointer.
 *
 * # Safety
 *
 * - Assumes `ptr` is a valid C string pointer.
 */
struct PositionId_t position_id_new(const char *ptr);

struct PositionId_t position_id_clone(const struct PositionId_t *position_id);

/**
 * Frees the memory for the given `position_id` by dropping.
 */
void position_id_drop(struct PositionId_t position_id);

/**
 * Returns a [`PositionId`] identifier as a C string pointer.
 */
const char *position_id_to_cstr(const struct PositionId_t *position_id);

uint8_t position_id_eq(const struct PositionId_t *lhs, const struct PositionId_t *rhs);

uint64_t position_id_hash(const struct PositionId_t *position_id);

/**
 * Returns a Nautilus identifier from a C string pointer.
 *
 * # Safety
 *
 * - Assumes `ptr` is a valid C string pointer.
 */
struct StrategyId_t strategy_id_new(const char *ptr);

struct StrategyId_t strategy_id_clone(const struct StrategyId_t *strategy_id);

/**
 * Frees the memory for the given `strategy_id` by dropping.
 */
void strategy_id_drop(struct StrategyId_t strategy_id);

/**
 * Returns a [`StrategyId`] as a C string pointer.
 */
const char *strategy_id_to_cstr(const struct StrategyId_t *strategy_id);

/**
 * Returns a Nautilus identifier from a C string pointer.
 *
 * # Safety
 *
 * - Assumes `ptr` is a valid C string pointer.
 */
struct Symbol_t symbol_new(const char *ptr);

struct Symbol_t symbol_clone(const struct Symbol_t *symbol);

/**
 * Frees the memory for the given [Symbol] by dropping.
 */
void symbol_drop(struct Symbol_t symbol);

/**
 * Returns a [`Symbol`] as a C string pointer.
 */
const char *symbol_to_cstr(const struct Symbol_t *symbol);

uint8_t symbol_eq(const struct Symbol_t *lhs, const struct Symbol_t *rhs);

uint64_t symbol_hash(const struct Symbol_t *symbol);

/**
 * Returns a Nautilus identifier from a C string pointer.
 *
 * # Safety
 *
 * - Assumes `ptr` is a valid C string pointer.
 */
struct TradeId_t trade_id_new(const char *ptr);

struct TradeId_t trade_id_clone(const struct TradeId_t *trade_id);

/**
 * Frees the memory for the given `trade_id` by dropping.
 */
void trade_id_drop(struct TradeId_t trade_id);

/**
 * Returns [`TradeId`] as a C string pointer.
 */
const char *trade_id_to_cstr(const struct TradeId_t *trade_id);

uint8_t trade_id_eq(const struct TradeId_t *lhs, const struct TradeId_t *rhs);

uint64_t trade_id_hash(const struct TradeId_t *trade_id);

/**
 * Returns a Nautilus identifier from a C string pointer.
 *
 * # Safety
 *
 * - Assumes `ptr` is a valid C string pointer.
 */
struct TraderId_t trader_id_new(const char *ptr);

struct TraderId_t trader_id_clone(const struct TraderId_t *trader_id);

/**
 * Frees the memory for the given `trader_id` by dropping.
 */
void trader_id_drop(struct TraderId_t trader_id);

/**
 * Returns a [`TraderId`] as a C string pointer.
 */
const char *trader_id_to_cstr(const struct TraderId_t *trader_id);

/**
 * Returns a Nautilus identifier from a C string pointer.
 *
 * # Safety
 *
 * - Assumes `ptr` is a valid C string pointer.
 */
struct Venue_t venue_new(const char *ptr);

struct Venue_t venue_clone(const struct Venue_t *venue);

/**
 * Frees the memory for the given `venue` by dropping.
 */
void venue_drop(struct Venue_t venue);

/**
 * Returns a [`Venue`] identifier as a C string pointer.
 */
const char *venue_to_cstr(const struct Venue_t *venue);

uint8_t venue_eq(const struct Venue_t *lhs, const struct Venue_t *rhs);

uint64_t venue_hash(const struct Venue_t *venue);

/**
 * Returns a Nautilus identifier from a C string pointer.
 *
 * # Safety
 *
 * - Assumes `ptr` is a valid C string pointer.
 */
struct VenueOrderId_t venue_order_id_new(const char *ptr);

struct VenueOrderId_t venue_order_id_clone(const struct VenueOrderId_t *venue_order_id);

/**
 * Frees the memory for the given `venue_order_id` by dropping.
 */
void venue_order_id_drop(struct VenueOrderId_t venue_order_id);

const char *venue_order_id_to_cstr(const struct VenueOrderId_t *venue_order_id);

uint8_t venue_order_id_eq(const struct VenueOrderId_t *lhs, const struct VenueOrderId_t *rhs);

uint64_t venue_order_id_hash(const struct VenueOrderId_t *venue_order_id);

struct OrderBook_API orderbook_new(struct InstrumentId_t instrument_id, enum BookType book_type);

void orderbook_drop(struct OrderBook_API book);

void orderbook_reset(struct OrderBook_API *book);

struct InstrumentId_t orderbook_instrument_id(const struct OrderBook_API *book);

enum BookType orderbook_book_type(const struct OrderBook_API *book);

uint64_t orderbook_sequence(const struct OrderBook_API *book);

uint64_t orderbook_ts_last(const struct OrderBook_API *book);

uint64_t orderbook_count(const struct OrderBook_API *book);

void orderbook_add(struct OrderBook_API *book,
                   struct BookOrder_t order,
                   uint64_t ts_event,
                   uint64_t sequence);

void orderbook_update(struct OrderBook_API *book,
                      struct BookOrder_t order,
                      uint64_t ts_event,
                      uint64_t sequence);

void orderbook_delete(struct OrderBook_API *book,
                      struct BookOrder_t order,
                      uint64_t ts_event,
                      uint64_t sequence);

void orderbook_clear(struct OrderBook_API *book, uint64_t ts_event, uint64_t sequence);

void orderbook_clear_bids(struct OrderBook_API *book, uint64_t ts_event, uint64_t sequence);

void orderbook_clear_asks(struct OrderBook_API *book, uint64_t ts_event, uint64_t sequence);

void orderbook_apply_delta(struct OrderBook_API *book, struct OrderBookDelta_t delta);

uint8_t orderbook_has_bid(struct OrderBook_API *book);

uint8_t orderbook_has_ask(struct OrderBook_API *book);

struct Price_t orderbook_best_bid_price(struct OrderBook_API *book);

struct Price_t orderbook_best_ask_price(struct OrderBook_API *book);

struct Quantity_t orderbook_best_bid_size(struct OrderBook_API *book);

struct Quantity_t orderbook_best_ask_size(struct OrderBook_API *book);

double orderbook_spread(struct OrderBook_API *book);

double orderbook_midpoint(struct OrderBook_API *book);

void orderbook_update_quote_tick(struct OrderBook_API *book, const struct QuoteTick_t *tick);

void orderbook_update_trade_tick(struct OrderBook_API *book, const struct TradeTick_t *tick);

CVec orderbook_simulate_fills(const struct OrderBook_API *book, struct BookOrder_t order);

void orderbook_check_integrity(const struct OrderBook_API *book);

void vec_fills_drop(CVec v);

/**
 * Returns a pretty printed [`OrderBook`] number of levels per side, as a C string pointer.
 */
const char *orderbook_pprint_to_cstr(const struct OrderBook_API *book, uintptr_t num_levels);

/**
 * Returns a [`Currency`] from pointers and primitives.
 *
 * # Safety
 * - Assumes `code_ptr` is a valid C string pointer.
 * - Assumes `name_ptr` is a valid C string pointer.
 */
struct Currency_t currency_from_py(const char *code_ptr,
                                   uint8_t precision,
                                   uint16_t iso4217,
                                   const char *name_ptr,
                                   enum CurrencyType currency_type);

struct Currency_t currency_clone(const struct Currency_t *currency);

void currency_drop(struct Currency_t currency);

const char *currency_to_cstr(const struct Currency_t *currency);

const char *currency_code_to_cstr(const struct Currency_t *currency);

const char *currency_name_to_cstr(const struct Currency_t *currency);

uint8_t currency_eq(const struct Currency_t *lhs, const struct Currency_t *rhs);

uint64_t currency_hash(const struct Currency_t *currency);

struct Money_t money_new(double amount, struct Currency_t currency);

struct Money_t money_from_raw(int64_t raw, struct Currency_t currency);

void money_drop(struct Money_t money);

double money_as_f64(const struct Money_t *money);

void money_add_assign(struct Money_t a, struct Money_t b);

void money_sub_assign(struct Money_t a, struct Money_t b);

struct Price_t price_new(double value, uint8_t precision);

struct Price_t price_from_raw(int64_t raw, uint8_t precision);

double price_as_f64(const struct Price_t *price);

void price_add_assign(struct Price_t a, struct Price_t b);

void price_sub_assign(struct Price_t a, struct Price_t b);

struct Quantity_t quantity_new(double value, uint8_t precision);

struct Quantity_t quantity_from_raw(uint64_t raw, uint8_t precision);

double quantity_as_f64(const struct Quantity_t *qty);

void quantity_add_assign(struct Quantity_t a, struct Quantity_t b);

void quantity_add_assign_u64(struct Quantity_t a, uint64_t b);

void quantity_sub_assign(struct Quantity_t a, struct Quantity_t b);

void quantity_sub_assign_u64(struct Quantity_t a, uint64_t b);

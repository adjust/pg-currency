CREATE TYPE currency;

CREATE FUNCTION currency_in(cstring)
    RETURNS currency
    AS '$libdir/currency.so'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION currency_out(currency)
    RETURNS cstring
    AS '$libdir/currency.so'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION currency_recv(internal)
    RETURNS currency
    AS '$libdir/currency.so'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION currency_send(currency)
    RETURNS bytea
    AS '$libdir/currency.so'
    LANGUAGE C IMMUTABLE STRICT;

CREATE TYPE currency (
    internallength = 1,
    input = currency_in,
    output = currency_out,
    send = currency_send,
    receive = currency_recv,
    alignment = char,
    PASSEDBYVALUE
);

COMMENT ON TYPE currency
  IS '1-byte ISO 4217 Currency Code';

CREATE FUNCTION currency_lt(currency, currency)
    RETURNS BOOL
    AS '$libdir/currency.so'
    LANGUAGE C IMMUTABLE STRICT;

COMMENT ON FUNCTION currency_lt(currency, currency) IS 'implementation of < operator';

CREATE FUNCTION currency_le(currency, currency)
    RETURNS BOOL
    AS '$libdir/currency.so'
    LANGUAGE C IMMUTABLE STRICT;

COMMENT ON FUNCTION currency_le(currency, currency) IS 'implementation of <= operator';

CREATE FUNCTION currency_eq(currency, currency)
    RETURNS BOOL
    AS '$libdir/currency.so'
    LANGUAGE C IMMUTABLE STRICT;

COMMENT ON FUNCTION currency_eq(currency, currency) IS 'implementation of = operator';

CREATE FUNCTION currency_neq(currency, currency)
    RETURNS BOOL
    AS '$libdir/currency.so'
    LANGUAGE C IMMUTABLE STRICT;

COMMENT ON FUNCTION currency_neq(currency, currency) IS 'implementation of <> operator';

CREATE FUNCTION currency_ge(currency, currency)
    RETURNS BOOL
    AS '$libdir/currency.so'
    LANGUAGE C IMMUTABLE STRICT;

COMMENT ON FUNCTION currency_ge(currency, currency) IS 'implementation of >= operator';

CREATE FUNCTION currency_gt(currency, currency)
    RETURNS BOOL
    AS '$libdir/currency.so'
    LANGUAGE C IMMUTABLE STRICT;

COMMENT ON FUNCTION currency_gt(currency, currency) IS 'implementation of > operator';

CREATE FUNCTION hash_currency(currency)
    RETURNS integer
    AS '$libdir/currency.so'
    LANGUAGE C IMMUTABLE STRICT;

COMMENT ON FUNCTION hash_currency(currency) IS 'hash';

CREATE OPERATOR < (
    leftarg = currency,
    rightarg = currency,
    procedure = currency_lt,
    commutator = >,
    negator   = >=,
    restrict = scalarltsel,
    join = scalarltjoinsel
);

COMMENT ON OPERATOR <(currency, currency) IS 'less than';

CREATE OPERATOR <= (
    leftarg = currency,
    rightarg = currency,
    procedure = currency_le,
    commutator = >=,
    negator   = >,
    restrict = scalarltsel,
    join = scalarltjoinsel
);

COMMENT ON OPERATOR <=(currency, currency) IS 'less than or equal';

CREATE OPERATOR = (
    leftarg = currency,
    rightarg = currency,
    procedure = currency_eq,
    commutator = =,
    negator   = <>,
    restrict = eqsel,
    join = eqjoinsel,
    HASHES, MERGES
);

COMMENT ON OPERATOR =(currency, currency) IS 'equal';

CREATE OPERATOR >= (
    leftarg = currency,
    rightarg = currency,
    procedure = currency_ge,
    commutator = <=,
    negator   = <,
    restrict = scalargtsel,
    join = scalargtjoinsel
);

COMMENT ON OPERATOR >=(currency, currency) IS 'greater than or equal';

CREATE OPERATOR > (
    leftarg = currency,
    rightarg = currency,
    procedure = currency_gt,
    commutator = <,
    negator   = <=,
    restrict = scalargtsel,
    join = scalargtjoinsel
);

COMMENT ON OPERATOR >(currency, currency) IS 'greater than';

CREATE OPERATOR <> (
    leftarg = currency,
    rightarg = currency,
    procedure = currency_neq,
    commutator = <>,
    negator = =,
    restrict = neqsel,
    join = neqjoinsel
);

COMMENT ON OPERATOR <>(currency, currency) IS 'not equal';

CREATE FUNCTION currency_cmp(currency, currency)
    RETURNS int4
    AS '$libdir/currency.so'
    LANGUAGE C IMMUTABLE STRICT;

CREATE OPERATOR CLASS currency_ops
    DEFAULT FOR TYPE currency USING btree AS
        OPERATOR        1       < ,
        OPERATOR        2       <= ,
        OPERATOR        3       = ,
        OPERATOR        4       >= ,
        OPERATOR        5       > ,
        FUNCTION        1       currency_cmp(currency, currency);

CREATE OPERATOR CLASS currency_ops
    DEFAULT FOR TYPE currency USING hash AS
        OPERATOR        1       = ,
        FUNCTION        1       hash_currency(currency);

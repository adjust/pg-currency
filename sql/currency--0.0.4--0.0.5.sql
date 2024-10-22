CREATE FUNCTION supported_currencies()
    RETURNS SETOF currency
    AS '$libdir/currency'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION currency_in(cstring)
    RETURNS currency
    AS '$libdir/currency'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION currency_out(currency)
    RETURNS cstring
    AS '$libdir/currency'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION currency_recv(internal)
    RETURNS currency
    AS '$libdir/currency'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION currency_send(currency)
    RETURNS bytea
    AS '$libdir/currency'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION currency_lt(currency, currency)
    RETURNS BOOL
    AS '$libdir/currency'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION currency_le(currency, currency)
    RETURNS BOOL
    AS '$libdir/currency'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION currency_eq(currency, currency)
    RETURNS BOOL
    AS '$libdir/currency'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION currency_neq(currency, currency)
    RETURNS BOOL
    AS '$libdir/currency'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION currency_ge(currency, currency)
    RETURNS BOOL
    AS '$libdir/currency'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION currency_gt(currency, currency)
    RETURNS BOOL
    AS '$libdir/currency'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION hash_currency(currency)
    RETURNS integer
    AS '$libdir/currency'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION currency_cmp(currency, currency)
    RETURNS int4
    AS '$libdir/currency'
    LANGUAGE C IMMUTABLE STRICT;

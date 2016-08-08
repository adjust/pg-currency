
CREATE FUNCTION supported_currencies()
    RETURNS SETOF currency
    AS '$libdir/currency.so'
    LANGUAGE C IMMUTABLE STRICT;


DO $$
DECLARE version_num integer;
BEGIN
  SELECT current_setting('server_version_num') INTO STRICT version_num;
  IF version_num > 90600 THEN
	EXECUTE $E$ ALTER FUNCTION currency_in(cstring) PARALLEL SAFE $E$;
	EXECUTE $E$ ALTER FUNCTION currency_out(currency) PARALLEL SAFE $E$;
	EXECUTE $E$ ALTER FUNCTION currency_recv(internal) PARALLEL SAFE $E$;
	EXECUTE $E$ ALTER FUNCTION currency_send(currency) PARALLEL SAFE $E$;
	EXECUTE $E$ ALTER FUNCTION currency_eq(currency, currency) PARALLEL SAFE $E$;
	EXECUTE $E$ ALTER FUNCTION currency_neq(currency, currency) PARALLEL SAFE $E$;
	EXECUTE $E$ ALTER FUNCTION currency_lt(currency, currency) PARALLEL SAFE $E$;
	EXECUTE $E$ ALTER FUNCTION currency_le(currency, currency) PARALLEL SAFE $E$;
	EXECUTE $E$ ALTER FUNCTION currency_gt(currency, currency) PARALLEL SAFE $E$;
	EXECUTE $E$ ALTER FUNCTION currency_ge(currency, currency) PARALLEL SAFE $E$;
	EXECUTE $E$ ALTER FUNCTION currency_cmp(currency, currency) PARALLEL SAFE $E$;
	EXECUTE $E$ ALTER FUNCTION hash_currency(currency) PARALLEL SAFE $E$;
  END IF;
END;
$$;


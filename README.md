[![Build Status](https://travis-ci.org/adjust/pg-currency.svg)](https://travis-ci.org/adjust/pg-currency)

# PG Currency

A 1-byte ISO 4217 Currency Code data-type for PostgreSQL.

### Installation

You can clone the extension and run the standard `make && make install` to
build it against your PostgreSQL server.

### Usage

The currency extension defines a data-type `currency`, which can be used, for
example, in `CREATE TABLE` statements. There're also comparison operators to
support ordering and `btree` indexing.

#### Using the currency data-type

The following example illustrates the use of the `country` type.

```SQL
CREATE TABLE transactions (id serial, payment_currency currency);

INSERT INTO transactions (values
  (1, 'USD'),
  (2, 'EUR'),
  (3, 'USD')
);

SELECT * FROM transactions ORDER BY payment_currency;
```

The result from the above execution will be:

```
id | payment_currency
----+------------------
  2 | EUR
  1 | USD
  3 | USD
(3 rows)
```

#### List of supported currencies

To get a list of supported for the installed version, you can use the `supported_currencies` SRF.

```
SELECT * FROM supported_currencies();
```

This will return a set of the supported currencies with no specific ordering.

```
SELECT * FROM supported_currencies() currency ORDER BY currency;
```

### Development

To run the tests, clone and run `make && make install && make installcheck`.
[Dumbo](https://github.com/adjust/dumbo) is the recommended development tool for
the extension.

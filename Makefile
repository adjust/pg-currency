EXTENSION = currency
EXTVERSION = $(shell grep default_version $(EXTENSION).control | \
                sed -e "s/default_version[[:space:]]*=[[:space:]]*'\([^']*\)'/\1/")
DATA = $(wildcard sql/*--*.sql)

MODULE_big = currency
OBJS = src/currency.o

TESTS        = setup $(filter-out test/sql/setup.sql test/sql/update.sql, $(wildcard test/sql/*.sql))

REGRESS      = $(patsubst test/sql/%.sql,%,$(TESTS))
REGRESS_OPTS = --inputdir=test

all: concat

concat:
	echo > sql/$(EXTENSION)--$(EXTVERSION).sql
	cat $(filter-out $(wildcard sql/*--*.sql),$(wildcard sql/*.sql)) >> sql/$(EXTENSION)--$(EXTVERSION).sql


PG_CONFIG ?= pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)

ifeq ($(shell test $(VERSION_NUM) -lt 90600; echo $$?),0)
REGRESS := $(filter-out parallel_test, $(REGRESS))
endif


BEGIN;
SET max_parallel_workers_per_gather=4;
DO $$
BEGIN
    IF current_setting('server_version_num')::int >= 160000 THEN
        EXECUTE 'SET debug_parallel_query = on';
    ELSE
        EXECUTE 'SET force_parallel_mode = on';
    END IF;
END $$;

CREATE TABLE parallel_test(i int, c currency) WITH (parallel_workers = 4);
INSERT INTO parallel_test (i, c)
SELECT i, c.country
FROM generate_series(1,1e6) i,
LATERAL (SELECT CASE WHEN i % 3 = 0 THEN 'USD'::currency
                     WHEN i % 3 = 1 THEN 'CAD'::currency
                     WHEN i % 3 = 2 THEN 'EUR'::currency
         END as country) c;

EXPLAIN (costs off,verbose)
SELECT COUNT(*) FROM parallel_test WHERE  c = 'USD';;

EXPLAIN (costs off,verbose)
SELECT c, COUNT(*) FROM parallel_test GROUP BY 1;
ROLLBACK;

BEGIN;
CREATE TABLE before (a currency);
INSERT INTO before values ('ZMW'),('ZWD'),(NULL),('UYU'),('UAH');
CREATE TABLE after (a currency);
COPY before TO '/tmp/tst' WITH (FORMAT binary);
COPY after FROM '/tmp/tst' WITH (FORMAT binary);
SELECT * FROM after;
ROLLBACK;

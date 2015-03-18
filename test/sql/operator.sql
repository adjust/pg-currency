SELECT 'AED'::currency < 'AED'::currency;
SELECT 'AED'::currency < 'AFN'::currency;
SELECT 'AFN'::currency < 'AED'::currency;

SELECT 'AED'::currency <= 'AED'::currency;
SELECT 'AED'::currency <= 'AFN'::currency;
SELECT 'AFN'::currency <= 'AED'::currency;

SELECT 'AED'::currency = 'AED'::currency;
SELECT 'AED'::currency = 'AFN'::currency;
SELECT 'AFN'::currency = 'AED'::currency;

SELECT 'AED'::currency >= 'AED'::currency;
SELECT 'AED'::currency >= 'AFN'::currency;
SELECT 'AFN'::currency >= 'AED'::currency;

SELECT 'AED'::currency > 'AED'::currency;
SELECT 'AED'::currency > 'AFN'::currency;
SELECT 'AFN'::currency > 'AED'::currency;

SELECT 'AED'::currency <> 'AED'::currency;
SELECT 'AED'::currency <> 'AFN'::currency;
SELECT 'AFN'::currency <> 'AED'::currency;

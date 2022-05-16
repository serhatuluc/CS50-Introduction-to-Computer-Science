-- Keep a log of any SQL queries you execute as you solve the mystery.


-- Whe have learned theft was happened in Humprey Street after the query below was implemented
SELECT description,street FROM crime_scene_reports WHERE  day = 28 AND month = 7;
-- Output:Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time – each of
-- their interview transcripts mentions the bakery. | Humphrey Street |



-- To read interviews
SELECT transcript,name FROM interviews WHERE month = 7 AND day = 28 AND  transcript LIKE "%bakery%"
--Output:
-- | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking
-- lot and drive away. If you have security footage from the bakery parking lot, you might want to
-- look for cars that left the parking lot in that time frame.
--                    | Ruth    |
-- | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I
-- arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing
-- some money.
--    | Eugene  |
-- | As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville
-- tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
-- | Raymond |


-- To find the licence plate of car the thief used to runaway
SELECT license_plate,day,month,hour,minute,activity FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND minute > 15 AND minute <30 AND activity = "exit";
-- Output:
-- +---------------+-----+-------+------+--------+----------+
-- | license_plate | day | month | hour | minute | activity |
-- +---------------+-----+-------+------+--------+----------+
-- | 5P2BI95       | 28  | 7     | 10   | 16     | exit     |
-- | 94KL13X       | 28  | 7     | 10   | 18     | exit     |
-- | 6P58WS2       | 28  | 7     | 10   | 18     | exit     |
-- | 4328GD8       | 28  | 7     | 10   | 19     | exit     |
-- | G412CB7       | 28  | 7     | 10   | 20     | exit     |
-- | L93JTIZ       | 28  | 7     | 10   | 21     | exit     |
-- | 322W7JE       | 28  | 7     | 10   | 23     | exit     |
-- | 0NTHK55       | 28  | 7     | 10   | 23     | exit     |
-- +---------------+-----+-------+------+--------+----------+

-- Let's find who parked there
SELECT name FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs
 WHERE day = 28 AND month = 7 AND hour = 10
 AND minute > 15 AND minute <30 AND activity = "exit");
 -- +---------+
-- |  name   |
-- +---------+
-- | Vanessa |
-- | Barry   |
-- | Iman    |
-- | Sofia   |
-- | Luca    |
-- | Diana   |
-- | Kelsey  |
-- | Bruce   |
-- +---------+


-- To check atm transactions
SELECT * FROM atm_transactions WHERE atm_location ="Leggett Street" AND day = 28 AND month = 7 AND transaction_type = "withdraw";
-- Output:
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
-- | 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
-- | 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- | 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
-- | 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
-- | 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+

-- To find who withdrew money from bank at that time
SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id WHERE account_number IN
(SELECT account_number FROM atm_transactions
WHERE atm_location ="Leggett Street" AND day = 28
AND month = 7 AND transaction_type = "withdraw");
-- Output:
-- +---------+
-- | Bruce   |
-- | Diana   |
-- | Brooke  |
-- | Kenny   |
-- | Iman    |
-- | Luca    |
-- | Taylor  |
-- | Benista |
-- +---------+


-- To check phone calls
SELECT caller FROM phone_calls WHERE day = 28 AND month = 7;

-- To find who had call on that day
SELECT name FROM people WHERE phone_number IN
(SELECT caller FROM phone_calls WHERE day = 28 AND month = 7);

-- Flights that day after theft
SELECT * FROM flights WHERE day = 29 AND  month = 7 ORDER BY hour,minute LIMIT 1;
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+

-- People who attended to the first flight that is out of Fiftyville
SELECT name FROM people
WHERE passport_number IN
(SELECT passport_number from passengers
JOIN flights ON flights.id = passengers.flight_id
WHERE flight_id  IN
(SELECT id FROM flights
 WHERE day = 29 AND  month = 7 ORDER BY hour,minute LIMIT 1));
-- Output:
-- +--------+
-- |  name  |
-- +--------+
-- | Kenny  |
-- | Sofia  |
-- | Taylor |
-- | Luca   |
-- | Kelsey |
-- | Edward |
-- | Bruce  |
-- | Doris  |
-- +--------+


-- Comparing result of people who attended in the flight and the result of people who withdrew money and lastly
-- the result of people who had the call and also who parked at bakery
-- I know it looks complicated but it is just combination of all
SELECT name FROM people
WHERE passport_number IN
-- it checks if people who had flight joins with other
(SELECT passport_number from passengers
JOIN flights ON flights.id = passengers.flight_id
WHERE flight_id  IN
(SELECT id FROM flights
 WHERE day = 29 AND  month = 7 ORDER BY hour,minute LIMIT 1))

-- it checks if people who withdrew money joins with other
and name IN
 (SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id WHERE account_number IN
(SELECT account_number FROM atm_transactions
WHERE atm_location ="Leggett Street" AND day = 28
AND month = 7 AND transaction_type = "withdraw"))

-- it checks if people who had call on that day joins with other
and name in
(SELECT name FROM people WHERE phone_number IN
(SELECT caller FROM phone_calls WHERE day = 28 AND month = 7))

-- it checks if people who parked joins with other
and name IN (SELECT name FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs
 WHERE day = 28 AND month = 7 AND hour = 10
 AND minute > 15 AND minute <30 AND activity = "exit"));
 --It finds just one name
-- Output:
-- +-------+
-- | name  |
-- +-------+
-- | Bruce |
-- +-------+

-- Now we have a name let's find where run
SELECT city FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE day = 29 AND  month = 7 ORDER BY hour,minute LIMIT 1;
-- Output:
-- +---------------+
-- |     city      |
-- +---------------+
-- | New York City |
-- +---------------+

-- Now let's find who was accmplice
SELECT phone_number FROM people
WHERE name = "Bruce";

SELECT name FROM people WHERE phone_number IN
(SELECT receiver FROM phone_calls WHERE day = 28 AND month = 7 AND caller = "(367) 555-5533");










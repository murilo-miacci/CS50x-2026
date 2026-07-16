-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE year = 2025 AND month = 7 AND day = 28 AND street LIKE "%Humphrey%";

SELECT name, transcript FROM interviews WHERE year = 2025 AND month = 7 and day = 28;

SELECT account_number, atm_location, transaction_type, amount FROM atm_transactions WHERE year = 2025 AND month = 7 AND day = 28 AND atm_location = "Leggett Street";

SELECT bank_accounts.account_number, person_id, atm_transactions.atm_location, transaction_type, amount FROM bank_accou
nts JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number WHERE atm_location = "Leggett Stree
t" AND year = 2025 AND month = 7 and day = 28;

SELECT hour, minute, activity, license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2025 AND hour BETWEEN 9 AND 11;

Bruce|(367) 555-5533|5773159633|94KL13X

Sofia|(130) 555-0289|1695452385|G412CB7

Kelsey|(499) 555-9472|8294398571|0NTHK55

SELECT name FROM people WHERE phone_number = "(996) 555-8899";

SELECT full_name, city FROM airports WHERE id = 4;

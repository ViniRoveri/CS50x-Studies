-- Keep a log of any SQL queries you execute as you solve the mystery.


--Find crime report
SELECT description FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28
AND street = 'Humphrey Street';


-- See interviews
SELECT transcript FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28
AND transcript LIKE '%bakery%';


-- Name of the thief:
SELECT name as thiefName FROM people
WHERE id IN (
    -- List of person_id by license plate
    SELECT id AS idThiefByLicensePlate FROM people
    WHERE license_plate in (
        -- Get license plates that could be
        SELECT license_plate FROM bakery_security_logs
        WHERE year = 2021 AND month = 7 AND day = 28
        AND hour = 10 AND minute > 15 AND minute <= 25
        AND activity = 'exit'
    )
)
AND id IN (
    -- List of person_id by bank account
    SELECT person_id AS idThiefByBankAccount FROM bank_accounts
    WHERE account_number IN (
        -- Get account numbers in atm history
        SELECT account_number FROM atm_transactions
        WHERE year = 2021 AND month = 7 AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
    )
)
AND id IN (
    --List of person_id by caller phone number
    SELECT id AS idThiefByPhone FROM people
    WHERE phone_number IN (
        -- Get phone calls caller
        SELECT caller FROM phone_calls
        WHERE year = 2021 AND month = 7 AND day = 28
        AND duration < 60
    )
)
AND id IN (
    -- Get list of person_id by passport number
    SELECT id AS idThiefByPassport FROM people
    WHERE passport_number IN (
        -- Get passengers of flight
        SELECT passport_number FROM passengers
        WHERE flight_id = (
            -- Get flight id
            SELECT id FROM flights
            WHERE year = 2021 AND month = 7 AND day = 29
            AND origin_airport_id = (
                -- Get Fiftyville airport id
                SELECT id FROM airports
                WHERE city = 'Fiftyville'
            )
            ORDER BY hour, minute
            LIMIT 1
        )
    )
);


-- Name of the accomplice:
SELECT name as accompliceName FROM people
WHERE phone_number = (
    SELECT receiver FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28
    AND caller = (
        SELECT phone_number FROM people
        WHERE name = 'Bruce'
    )
);


-- City they went to:
SELECT city as destinationCity FROM airports
WHERE id = (
    -- Get destination airport id
    SELECT destination_airport_id FROM flights
    WHERE year = 2021 AND month = 7 AND day = 29
    AND origin_airport_id = (
        -- Get Fiftyville airport id
        SELECT id FROM airports
        WHERE city = 'Fiftyville'
    )
    ORDER BY hour, minute
    LIMIT 1
);


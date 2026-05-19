SELECT first_name, last_name, city, state
FROM person FULL OUTER JOIN address
    ON person.person_id = address.person_id
WHERE person.person_id IS NOT NULL
;
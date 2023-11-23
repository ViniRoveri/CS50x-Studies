SELECT name FROM people
WHERE id IN (
    --list of people_id in movies with Kevin
    SELECT person_id FROM stars
    WHERE movie_id IN (
        --list of movie_id with Kevin
        SELECT movie_id FROM stars
        JOIN people ON stars.person_id = people.id
        WHERE people.name = 'Kevin Bacon'
    )
)
AND NAME != 'Kevin Bacon'

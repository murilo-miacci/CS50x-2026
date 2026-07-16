-- 13. Names of all people who starred in a movie in which Kevin Bacon also starred

SELECT DISTINCT name FROM people
JOIN stars ON stars.person_id = people.id
WHERE movie_id IN
(
    SELECT movie_id from stars
    WHERE person_id =
    (
        SELECT id FROM people
        WHERE name = "Kevin Bacon"
    )
);

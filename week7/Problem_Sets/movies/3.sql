-- 3. Titles of all movies since 2018, in alphabetical order

SELECT COUNT(title) from movies WHERE year >= 2018 ORDER BY titl
e ASC;
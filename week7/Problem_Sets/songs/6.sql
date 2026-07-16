SELECT songs.name FROM songs
JOIN artists ON songs.artist_id = artists.id
WHERE artists.name LIKE "Post%";

-- Another way to do it (CS50 oficial)
SELECT name
FROM songs
WHERE artist_id =
(
    SELECT id
    FROM artists
    WHERE name = 'Post Malone'
);

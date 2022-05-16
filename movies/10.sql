SELECT name FROM people
JOIN movies ON directors.person_id = people.id
JOIN directors ON movies.id = directors.movie_id
JOIN ratings ON movies.id = ratings.movie_id
WHERE rating >= 9.0;
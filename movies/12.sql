SELECT title FROM movies
JOIN people ON stars.person_id = people.id
JOIN stars ON movies.id = stars.movie_id
JOIN ratings ON movies.id = ratings.movie_id
WHERE ( name = "Helena Bonham Carter")
and title IN
(SELECT title FROM movies
JOIN people ON stars.person_id = people.id
JOIN stars ON movies.id = stars.movie_id
JOIN ratings ON movies.id = ratings.movie_id
WHERE ( name = "Johnny Depp"));


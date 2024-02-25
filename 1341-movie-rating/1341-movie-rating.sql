# Write your MySQL query statement below
(select u.name as results
from MovieRating mr left join Users u
on mr.user_id = u.user_id
group by mr.user_id
order by count(mr.user_id) desc, u.name asc
limit 1)
union all
(select m.title as results
from MovieRating mr2 left join Movies m
on mr2.movie_id = m.movie_id
where mr2.created_at >= '2020-02-01' and mr2.created_at <= '2020-02-29'
group by mr2.movie_id
order by avg(mr2.rating) desc, m.title asc
limit 1)


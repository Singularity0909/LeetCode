
-- @Title: 合作过至少三次的演员和导演 (Actors and Directors Who Cooperated At Least Three Times)
-- @Author: Singularity0909
-- @Date: 2020-09-26 21:26:11
-- @Runtime: 271 ms
-- @Memory: 0 B

select actor_id, director_id
from ActorDirector
group by actor_id, director_id
having count(*) >= 3

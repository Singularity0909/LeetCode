
-- @Title: 不同性别每日分数总计 (Running Total for Different Genders)
-- @Author: Singularity0909
-- @Date: 2020-11-08 21:54:37
-- @Runtime: 1270 ms
-- @Memory: 0 B

select t1.gender, t1.day, 
(
    select sum(t2.score_points)
    from Scores t2
    where t2.gender = t1.gender and t2.day <= t1.day
) total
from Scores t1
group by t1.gender, t1.day
order by t1.gender, t1.day

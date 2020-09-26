
-- @Title: 有趣的电影 (Not Boring Movies)
-- @Author: Singularity0909
-- @Date: 2020-09-26 21:07:31
-- @Runtime: 161 ms
-- @Memory: 0 B

select *
from cinema t
where t.id % 2 = 1 and t.description != 'boring'
order by rating desc

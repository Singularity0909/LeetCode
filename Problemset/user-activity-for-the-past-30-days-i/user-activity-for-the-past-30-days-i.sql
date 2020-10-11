
-- @Title: 查询近30天活跃用户数 (User Activity for the Past 30 Days I)
-- @Author: Singularity0909
-- @Date: 2020-10-11 10:17:07
-- @Runtime: 321 ms
-- @Memory: 0 B

select t.activity_date day, count(distinct t.user_id) active_users
from Activity t
where datediff('2019-07-27', t.activity_date) < 30
group by t.activity_date
order by t.activity_date

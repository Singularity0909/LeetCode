
-- @Title: 每日新用户统计 (New Users Daily Count)
-- @Author: Singularity0909
-- @Date: 2020-10-10 10:16:14
-- @Runtime: 1405 ms
-- @Memory: 0 B

select t.activity_date login_date, count(distinct t.user_id) user_count
from Traffic t
where datediff('2019-06-30', t.activity_date) <= 90 and t.activity = 'login' and (
    select min(t1.activity_date)
    from Traffic t1
    where t1.user_id = t.user_id and t1.activity = 'login'
    group by t1.user_id
) >= t.activity_date
group by t.activity_date

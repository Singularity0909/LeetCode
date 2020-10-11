
-- @Title: 过去30天的用户活动 II (User Activity for the Past 30 Days II)
-- @Author: Singularity0909
-- @Date: 2020-10-11 23:57:37
-- @Runtime: 353 ms
-- @Memory: 0 B

select ifnull(round(count(distinct t.session_id) / count(distinct t.user_id), 2), 0) average_sessions_per_user
from Activity t
where datediff('2019-07-27', t.activity_date) < 30

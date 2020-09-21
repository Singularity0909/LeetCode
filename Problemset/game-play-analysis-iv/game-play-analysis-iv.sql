
-- @Title: 游戏玩法分析 IV (Game Play Analysis IV)
-- @Author: Singularity0909
-- @Date: 2020-09-19 10:19:57
-- @Runtime: 404 ms
-- @Memory: 0 B

select round(count(*) / 
(
    select count(distinct player_id)
    from Activity
), 2) fraction
from Activity a
where (a.player_id, a.event_date) in
(
    select player_id, date(min(event_date) + 1)
    from Activity
    group by player_id
)

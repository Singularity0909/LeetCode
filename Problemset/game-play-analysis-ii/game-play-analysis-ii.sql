
-- @Title: 游戏玩法分析 II (Game Play Analysis II)
-- @Author: Singularity0909
-- @Date: 2020-09-18 08:22:24
-- @Runtime: 417 ms
-- @Memory: 0 B

select a.player_id, a.device_id
from Activity a
where (a.player_id, a.event_date) in
(
    select player_id, min(event_date)
    from Activity
    group by player_id
)

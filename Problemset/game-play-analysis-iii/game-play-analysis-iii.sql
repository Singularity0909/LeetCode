
-- @Title: 游戏玩法分析 III (Game Play Analysis III)
-- @Author: Singularity0909
-- @Date: 2020-09-19 09:48:14
-- @Runtime: 617 ms
-- @Memory: 0 B

select a1.player_id, a1.event_date, sum(a2.games_played) games_played_so_far
from Activity a1, Activity a2
where a1.player_id = a2.player_id and a1.event_date >= a2.event_date
group by a1.player_id, a1.event_date

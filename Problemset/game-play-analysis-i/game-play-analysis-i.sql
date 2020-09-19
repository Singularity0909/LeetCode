
-- @Title: 游戏玩法分析 I (Game Play Analysis I)
-- @Author: Singularity0909
-- @Date: 2020-09-18 00:37:19
-- @Runtime: 395 ms
-- @Memory: 0 B

select player_id, min(event_date) as first_login from Activity group by player_id

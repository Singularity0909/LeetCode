
-- @Title: 最后一个能进入电梯的人 (Last Person to Fit in the Elevator)
-- @Author: Singularity0909
-- @Date: 2020-11-08 21:24:31
-- @Runtime: 1455 ms
-- @Memory: 0 B

select t.person_name
from Queue t
where
(
    select sum(t1.weight)
    from Queue t1
    where t1.turn <= t.turn
) <= 1000
order by t.turn desc
limit 1

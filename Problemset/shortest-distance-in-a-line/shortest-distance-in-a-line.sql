
-- @Title: 直线上的最近距离 (Shortest Distance in a Line)
-- @Author: Singularity0909
-- @Date: 2020-09-23 22:14:40
-- @Runtime: 190 ms
-- @Memory: 0 B

select min(abs(t1.x - t2.x)) shortest
from point t1 join point t2
where t1.x != t2.x

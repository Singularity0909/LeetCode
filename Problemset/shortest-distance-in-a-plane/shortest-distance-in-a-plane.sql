
-- @Title: 平面上的最近距离 (Shortest Distance in a Plane)
-- @Author: Singularity0909
-- @Date: 2020-09-23 22:13:11
-- @Runtime: 169 ms
-- @Memory: 0 B

select round(min(sqrt(pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2))), 2) shortest
from point_2d t1 join point_2d t2
where t1.x != t2.x or t1.y != t2.y


-- @Title: 判断三角形 (Triangle Judgement)
-- @Author: Singularity0909
-- @Date: 2020-09-23 22:00:30
-- @Runtime: 228 ms
-- @Memory: 0 B

select x, y, z, if (x + y > z and x + z > y and y + z > x, 'Yes', 'No') triangle
from triangle

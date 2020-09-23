
-- @Title: 2016年的投资 (Investments in 2016)
-- @Author: Singularity0909
-- @Date: 2020-09-23 20:27:31
-- @Runtime: 416 ms
-- @Memory: 0 B

select round(sum(t1.TIV_2016), 2) TIV_2016
from insurance t1
where t1.TIV_2015 in
(
    select t2.TIV_2015
    from insurance t2
    where t2.PID != t1.PID
)
and (t1.LAT, t1.LON) not in
(
    select t2.LAT, t2.LON
    from insurance t2
    where t2.PID != t1.PID
)


-- @Title: 只出现一次的最大数字 (Biggest Single Number)
-- @Author: Singularity0909
-- @Date: 2020-09-26 21:03:46
-- @Runtime: 271 ms
-- @Memory: 0 B

select max(num) num from
(
    select num
    from my_numbers
    group by num
    having count(*) = 1
) tb

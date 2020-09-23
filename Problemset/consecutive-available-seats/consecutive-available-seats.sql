
-- @Title: 连续空余座位 (Consecutive Available Seats)
-- @Author: Singularity0909
-- @Date: 2020-09-23 21:44:12
-- @Runtime: 253 ms
-- @Memory: 0 B

select t1.seat_id from cinema t1
where t1.free = 1 and
(
    select count(*)
    from cinema t2
    where t2.free = 1 and abs(t2.seat_id - t1.seat_id) = 1
) >= 1
order by t1.seat_id

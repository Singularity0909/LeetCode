
-- @Title: 小众书籍 (Unpopular Books)
-- @Author: Singularity0909
-- @Date: 2020-10-08 17:34:17
-- @Runtime: 1229 ms
-- @Memory: 0 B

select t1.book_id, t1.name
from Books t1
where datediff('2019-06-23', t1.available_from) >= 30 and ifnull(
(
    select sum(t2.quantity)
    from Orders t2
    where t2.book_id = t1.book_id and datediff('2019-06-23', t2.dispatch_date) <= 365
), 0) < 10

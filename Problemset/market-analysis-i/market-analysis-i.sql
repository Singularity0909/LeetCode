
-- @Title: 市场分析 I (Market Analysis I)
-- @Author: Singularity0909
-- @Date: 2020-10-15 20:53:38
-- @Runtime: 857 ms
-- @Memory: 0 B

select t1.user_id buyer_id, t1.join_date, ifnull(t3.cnt, 0) orders_in_2019
from Users t1 left join
(
    select t2.buyer_id, count(distinct t2.order_id) cnt
    from Orders t2
    where year(t2.order_date) = '2019'
    group by t2.buyer_id
) t3
on t1.user_id = t3.buyer_id
order by t1.user_id

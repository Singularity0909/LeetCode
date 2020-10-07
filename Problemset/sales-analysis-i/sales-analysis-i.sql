
-- @Title: 销售分析 I  (Sales Analysis I)
-- @Author: Singularity0909
-- @Date: 2020-10-07 10:38:30
-- @Runtime: 839 ms
-- @Memory: 0 B

select t2.seller_id
from Product t1 join Sales t2
on t1.product_id = t2.product_id
group by t2.seller_id
having sum(t2.price) >= all (
    select sum(t4.price)
    from Product t3 join Sales t4
    on t3.product_id = t4.product_id
    group by t4.seller_id
)

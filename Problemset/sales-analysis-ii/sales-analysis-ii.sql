
-- @Title: 销售分析 II (Sales Analysis II)
-- @Author: Singularity0909
-- @Date: 2020-10-07 10:58:35
-- @Runtime: 962 ms
-- @Memory: 0 B

select distinct t.buyer_id
from Sales t
where exists 
(
    select *
    from Product t1 join Sales t2
    on t1.product_id = t2.product_id
    where t1.product_name = 'S8' and t2.buyer_id = t.buyer_id
)
and not exists
(
    select *
    from Product t3 join Sales t4
    on t3.product_id = t4.product_id
    where t3.product_name = 'iPhone' and t4.buyer_id = t.buyer_id
)

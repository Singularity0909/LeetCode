
-- @Title: 买下所有产品的客户 (Customers Who Bought All Products)
-- @Author: Singularity0909
-- @Date: 2020-09-26 21:24:46
-- @Runtime: 402 ms
-- @Memory: 0 B

select t1.customer_id
from Customer t1
group by t1.customer_id
having count(distinct t1.product_key) = 
(
    select count(*)
    from Product
)

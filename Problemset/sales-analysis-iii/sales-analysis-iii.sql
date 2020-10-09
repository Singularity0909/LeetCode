
-- @Title: 销售分析III (Sales Analysis III)
-- @Author: Singularity0909
-- @Date: 2020-10-08 17:18:11
-- @Runtime: 827 ms
-- @Memory: 0 B

select t1.product_id, t1.product_name
from Product t1
where t1.product_id in (
    select t2.product_id
    from Sales t2
    where t2.sale_date >= '2019-01-01' and t2.sale_date <= '2019-03-31'
)
and t1.product_id not in (
    select t2.product_id
    from Sales t2
    where t2.sale_date < '2019-01-01' or t2.sale_date > '2019-03-31'
)

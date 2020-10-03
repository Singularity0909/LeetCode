
-- @Title: 产品销售分析 II (Product Sales Analysis II)
-- @Author: Singularity0909
-- @Date: 2020-09-28 01:32:06
-- @Runtime: 838 ms
-- @Memory: 0 B

select Product.product_id, sum(Sales.quantity) total_quantity
from Product join Sales
on Product.product_id = Sales.product_id
group by Product.product_id

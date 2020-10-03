
-- @Title: 产品销售分析 I (Product Sales Analysis I)
-- @Author: Singularity0909
-- @Date: 2020-09-28 01:30:40
-- @Runtime: 960 ms
-- @Memory: 0 B

select Product.product_name, Sales.year, Sales.price
from Product join Sales
on Product.product_id = Sales.product_id

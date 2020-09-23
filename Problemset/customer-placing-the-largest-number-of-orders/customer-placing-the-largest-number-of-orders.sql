
-- @Title: 订单最多的客户 (Customer Placing the Largest Number of Orders)
-- @Author: Singularity0909
-- @Date: 2020-09-23 20:30:49
-- @Runtime: 386 ms
-- @Memory: 0 B

select customer_number
from orders
group by customer_number
order by count(*) desc
limit 1

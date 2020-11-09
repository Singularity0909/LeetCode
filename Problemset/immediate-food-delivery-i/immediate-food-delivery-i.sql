
-- @Title: 即时食物配送 I (Immediate Food Delivery I)
-- @Author: Singularity0909
-- @Date: 2020-10-29 10:56:45
-- @Runtime: 373 ms
-- @Memory: 0 B

select round(ifnull(count(*) / 
(
    select count(*)
    from Delivery t2
) * 100, 0), 2) immediate_percentage
from Delivery t1
where t1.order_date = t1.customer_pref_delivery_date

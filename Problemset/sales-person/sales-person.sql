
-- @Title: 销售员 (Sales Person)
-- @Author: Singularity0909
-- @Date: 2020-09-23 21:46:38
-- @Runtime: 928 ms
-- @Memory: 0 B

select s.name
from salesperson s
where s.sales_id not in
(
    select o.sales_id
    from orders o join company c
    on o.com_id = c.com_id
    where c.name = 'RED'
)

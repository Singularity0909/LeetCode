
-- @Title: 餐馆营业额变化增长 (Restaurant Growth)
-- @Author: Singularity0909
-- @Date: 2020-09-26 22:51:13
-- @Runtime: 294 ms
-- @Memory: 0 B

select _date.visited_on visited_on, sum(c1.amount) amount, round(sum(c1.amount) / count(distinct c1.visited_on), 2) average_amount
from
(
    select distinct visited_on
    from Customer
    order by visited_on
    limit 6, 100000
) _date, Customer c1
where datediff(_date.visited_on, c1.visited_on) >= 0 and datediff(_date.visited_on, c1.visited_on) <= 6
group by _date.visited_on

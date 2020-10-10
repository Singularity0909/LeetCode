
-- @Title: 查询活跃业务 (Active Businesses)
-- @Author: Singularity0909
-- @Date: 2020-10-10 10:53:10
-- @Runtime: 664 ms
-- @Memory: 0 B

select business_id
from Events e
join (
    select event_type, avg(occurences) eventAvg
    from Events
    group by event_type
) e1 
on e.event_type = e1.event_type
where e.occurences > e1.eventAvg
group by business_id
having count(*) >= 2

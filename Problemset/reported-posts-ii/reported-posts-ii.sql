
-- @Title: 报告的记录 II (Reported Posts II)
-- @Author: Singularity0909
-- @Date: 2020-10-11 10:09:14
-- @Runtime: 704 ms
-- @Memory: 0 B

select round(avg(t.rate) * 100, 2) average_daily_percent
from
(
    select count(distinct t2.post_id) / count(distinct t1.post_id) rate
    from Actions t1 left join Removals t2
    on t1.post_id = t2.post_id
    where t1.extra = 'spam'
    group by t1.action_date
) t

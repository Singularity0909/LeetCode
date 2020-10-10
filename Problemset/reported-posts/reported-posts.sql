
-- @Title: 报告的记录 (Reported Posts)
-- @Author: Singularity0909
-- @Date: 2020-10-10 10:38:41
-- @Runtime: 426 ms
-- @Memory: 0 B

select t.extra report_reason, count(distinct post_id) report_count
from Actions t
where t.extra is not null and datediff('2019-07-05', t.action_date) = 1 and t.action = 'report'
group by t.extra

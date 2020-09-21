
-- @Title: 查询回答率最高的问题 (Get Highest Answer Rate Question)
-- @Author: Singularity0909
-- @Date: 2020-09-19 11:48:18
-- @Runtime: 187 ms
-- @Memory: 0 B

select s1.question_id survey_log
from
(
    select question_id, count(*) cnt
    from survey_log
    where action = 'show'
    group by question_id
) s1
left join
(
    select question_id, count(*) cnt
    from survey_log
    where action = 'answer'
    group by question_id
) s2
on s1.question_id = s2.question_id
order by (s2.cnt / s1.cnt) desc
limit 1

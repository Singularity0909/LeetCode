
-- @Title: 每位学生的最高成绩 (Highest Grade For Each Student)
-- @Author: Singularity0909
-- @Date: 2020-10-10 10:31:53
-- @Runtime: 2591 ms
-- @Memory: 0 B

select t.student_id, min(t.course_id) course_id, t.grade
from Enrollments t
where t.grade >= all (
    select t1.grade
    from Enrollments t1
    where t1.student_id = t.student_id
)
group by t.student_id
order by t.student_id

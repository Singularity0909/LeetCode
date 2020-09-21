
-- @Title: 统计各专业学生人数 (Count Student Number in Departments)
-- @Author: Singularity0909
-- @Date: 2020-09-19 12:03:28
-- @Runtime: 585 ms
-- @Memory: 0 B

select department.dept_name, count(distinct student.student_id) student_number
from department left join student
on department.dept_id = student.dept_id
group by department.dept_id
order by student_number desc

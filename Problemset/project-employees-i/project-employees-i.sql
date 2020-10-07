
-- @Title: 项目员工 I (Project Employees I)
-- @Author: Singularity0909
-- @Date: 2020-10-07 09:43:34
-- @Runtime: 626 ms
-- @Memory: 0 B

select t1.project_id, round(avg(t2.experience_years), 2) average_years
from Project t1 join Employee t2
on t1.employee_id = t2.employee_id
group by t1.project_id

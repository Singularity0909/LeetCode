
-- @Title: 项目员工 III (Project Employees III)
-- @Author: Singularity0909
-- @Date: 2020-10-07 10:22:33
-- @Runtime: 866 ms
-- @Memory: 0 B

select t1.project_id, t2.employee_id
from Project t1 join Employee t2
on t1.employee_id = t2.employee_id
where t2.experience_years >= all (
    select t4.experience_years
    from Project t3 join Employee t4
    on t3.employee_id = t4.employee_id
    where t3.project_id = t1.project_id
)

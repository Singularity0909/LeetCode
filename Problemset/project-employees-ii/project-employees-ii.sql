
-- @Title: 项目员工II (Project Employees II)
-- @Author: Singularity0909
-- @Date: 2020-10-07 09:50:08
-- @Runtime: 610 ms
-- @Memory: 0 B

select t1.project_id
from Project t1 join Employee t2
on t1.employee_id = t2.employee_id
group by t1.project_id
having count(*) >= all (
    select count(*) cnt
    from Project t3 join Employee t4
    on t3.employee_id = t4.employee_id
    group by t3.project_id
)

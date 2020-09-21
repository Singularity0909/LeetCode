
-- @Title: 员工奖金 (Employee Bonus)
-- @Author: Singularity0909
-- @Date: 2020-09-19 11:27:28
-- @Runtime: 207 ms
-- @Memory: 0 B

select Employee.name, Bonus.bonus
from Employee left join Bonus on Employee.empId = Bonus.empId 
where Bonus.bonus < 1000 or Bonus.bonus is null

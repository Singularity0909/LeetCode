
-- @Title: 至少有5名直接下属的经理 (Managers with at Least 5 Direct Reports)
-- @Author: Singularity0909
-- @Date: 2020-09-19 11:11:55
-- @Runtime: 226 ms
-- @Memory: 0 B

select e1.Name
from Employee e1, Employee e2
where e1.Id = e2.ManagerId
group by e1.Id
having count(*) >= 5


-- @Title: 组合两个表 (Combine Two Tables)
-- @Author: Singularity0909
-- @Date: 2020-03-19 12:19:49
-- @Runtime: 167 ms
-- @Memory: 0 B

# Write your MySQL query statement below
select Person.FirstName, Person.LastName, Address.City, Address.State
from Person left join Address on Person.PersonID = Address.PersonID

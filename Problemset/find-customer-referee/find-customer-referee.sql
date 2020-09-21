
-- @Title: 寻找用户推荐人 (Find Customer Referee)
-- @Author: Singularity0909
-- @Date: 2020-09-19 12:06:28
-- @Runtime: 345 ms
-- @Memory: 0 B

select name
from customer
where referee_id != 2 or referee_id is null

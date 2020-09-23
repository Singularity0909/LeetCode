
-- @Title: 好友申请 II ：谁有最多的好友 (Friend Requests II: Who Has the Most Friends)
-- @Author: Singularity0909
-- @Date: 2020-09-23 21:35:22
-- @Runtime: 208 ms
-- @Memory: 0 B

select t1.requester_id id, count(*) + 
ifnull((
    select count(*)
    from request_accepted t2
    where t2.accepter_id = t1.requester_id
    group by t2.accepter_id
), 0) num
from request_accepted t1
group by t1.requester_id
order by num desc
limit 1


-- @Title: 好友申请 I ：总体通过率 (Friend Requests I: Overall Acceptance Rate)
-- @Author: Singularity0909
-- @Date: 2020-09-23 21:22:26
-- @Runtime: 338 ms
-- @Memory: 0 B

select round(ifnull((select count(distinct ra.requester_id, ra.accepter_id) from request_accepted ra)  / (select count(distinct fr.sender_id, fr.send_to_id) from friend_request fr), 0), 2) accept_rate

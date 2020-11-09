
-- @Title: 页面推荐 (Page Recommendations)
-- @Author: Singularity0909
-- @Date: 2020-11-08 21:44:58
-- @Runtime: 402 ms
-- @Memory: 0 B

select distinct t2.page_id recommended_page
from Friendship t1, Likes t2
where ((t1.user1_id = 1 and t1.user2_id = t2.user_id) or (t1.user2_id = 1 and t1.user1_id = t2.user_id)) and t2.page_id not in
(
    select t3.page_id
    from Likes t3
    where t3.user_id = 1
)

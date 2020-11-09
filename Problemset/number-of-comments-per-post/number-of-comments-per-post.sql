
-- @Title: 每个帖子的评论数 (Number of Comments per Post)
-- @Author: Singularity0909
-- @Date: 2020-10-28 00:12:27
-- @Runtime: 966 ms
-- @Memory: 0 B

select distinct t1.sub_id post_id, ifnull(count(distinct t2.sub_id), 0) number_of_comments
from Submissions t1 left join Submissions t2
on t1.sub_id = t2.parent_id
where t1.parent_id is null
group by t1.sub_id

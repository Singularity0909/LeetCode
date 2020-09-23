
-- @Title: 二级关注者 (Second Degree Follower)
-- @Author: Singularity0909
-- @Date: 2020-09-24 01:06:51
-- @Runtime: 273 ms
-- @Memory: 0 B

select t1.followee follower, count(distinct(t1.follower)) num
from follow t1
where t1.followee in
(
    select t2.follower
    from follow t2
)
group by t1.followee
order by t1.followee

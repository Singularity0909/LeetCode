
-- @Title: 文章浏览 II (Article Views II)
-- @Author: Singularity0909
-- @Date: 2020-10-15 20:33:44
-- @Runtime: 387 ms
-- @Memory: 0 B

select distinct t1.viewer_id id
from Views t1
group by t1.viewer_id, t1.view_date
having count(distinct t1.article_id) >= 2
order by id asc


-- @Title: 文章浏览 I (Article Views I)
-- @Author: Singularity0909
-- @Date: 2020-10-14 20:55:44
-- @Runtime: 326 ms
-- @Memory: 0 B

select distinct t2.viewer_id id
from Views t1 join Views t2
where t1.article_id = t2.article_id and t1.author_id = t2.viewer_id
order by t2.viewer_id

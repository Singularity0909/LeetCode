
-- @Title: 树节点 (Tree Node)
-- @Author: Singularity0909
-- @Date: 2020-09-23 21:57:03
-- @Runtime: 353 ms
-- @Memory: 0 B

select t1.id id,
(
    case
    when
    (
        select t2.p_id
        from tree t2
        where t2.id = t1.id
    ) is null then 'Root'
    when
    (
        select count(*)
        from tree t2
        where t2.p_id = t1.id
    ) = 0 then 'Leaf'
    else 'Inner'
    end
) Type
from tree t1

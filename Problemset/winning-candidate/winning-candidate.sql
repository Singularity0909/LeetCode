
-- @Title: 当选者 (Winning Candidate)
-- @Author: Singularity0909
-- @Date: 2020-09-19 11:20:40
-- @Runtime: 321 ms
-- @Memory: 0 B

select Name
from Candidate
where Candidate.id = 
(
    select CandidateId
    from Vote
    group by CandidateId
    order by count(*) desc
    limit 1
)

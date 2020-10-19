
# @Title: 查找常用字符 (Find Common Characters)
# @Author: Singularity0909
# @Date: 2020-10-15 20:23:38
# @Runtime: 48 ms
# @Memory: 13.7 MB

class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        ans = ''
        for c in set(A[0]):
            v = min([s.count(c) for s in A])
            ans = ans + v * c
        return list(ans)

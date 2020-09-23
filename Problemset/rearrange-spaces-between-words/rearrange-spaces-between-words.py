
# @Title: 重新排列单词间的空格 (Rearrange Spaces Between Words)
# @Author: Singularity0909
# @Date: 2020-09-23 11:20:25
# @Runtime: 52 ms
# @Memory: 13.4 MB

class Solution:
    def reorderSpaces(self, text: str) -> str:
        cnt = sum([1 if i == ' ' else 0 for i in text])
        print(cnt)
        s = text.split()
        l = len(s)
        print(l)
        print(s)
        if l == 1:
            return s[0] + " " * cnt
        t = (" " * (cnt // (l - 1))).join(s)
        return t + " " * (cnt % (l - 1))

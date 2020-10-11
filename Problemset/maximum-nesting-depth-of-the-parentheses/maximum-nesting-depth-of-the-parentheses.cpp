
// @Title: 括号的最大嵌套深度 (Maximum Nesting Depth of the Parentheses)
// @Author: Singularity0909
// @Date: 2020-10-11 10:35:51
// @Runtime: 0 ms
// @Memory: 6.1 MB

class Solution {
public:
    int maxDepth(string s)
    {
        int cnt = 0, mx = 0;
        for (char c : s) {
            if (c == '(') {
                ++cnt;
                mx = max(mx, cnt);
            } else if (c == ')') {
                --cnt;
            }
        }
        return mx;
    }
};

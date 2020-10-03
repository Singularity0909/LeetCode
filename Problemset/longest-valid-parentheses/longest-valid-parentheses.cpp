
// @Title: 最长有效括号 (Longest Valid Parentheses)
// @Author: Singularity0909
// @Date: 2020-10-01 01:15:18
// @Runtime: 4 ms
// @Memory: 7.3 MB

class Solution {
public:
    int longestValidParentheses(string s)
    {
        int mx = 0, n = (int)s.length();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                mx = max(mx, dp[i]);
            }
        }
        return mx;
    }
};

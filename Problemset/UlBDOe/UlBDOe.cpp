
// @Title: 秋叶收藏集 (秋叶收藏集)
// @Author: Singularity0909
// @Date: 2020-10-01 16:47:13
// @Runtime: 708 ms
// @Memory: 111.6 MB

class Solution {
public:
    int minimumOperations(string s)
    {
        int n = (int)s.length();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = s[0] != 'r';
        dp[1][1] = (s[0] != 'r') + (s[1] != 'y');
        dp[2][2] = (s[0] != 'r') + (s[1] != 'y') + (s[2] != 'r');
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + (s[i] != 'r');
            if (i >= 2) {
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (s[i] != 'y');
            }
            if (i >= 3) {
                dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + (s[i] != 'r');
            }
        }
        return dp[n - 1][2];
    }
};

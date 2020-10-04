
// @Title: 礼物的最大价值 (礼物的最大价值 LCOF)
// @Author: Singularity0909
// @Date: 2020-09-04 01:58:50
// @Runtime: 20 ms
// @Memory: 9.4 MB

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        size_t n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = grid[i][0];
            if (i) dp[i][0] += dp[i - 1][0];
        }
        for (int i = 0; i < m; i++) {
            dp[0][i] = grid[0][i];
            if (i) dp[0][i] += dp[0][i - 1];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1][m - 1];
    }
};

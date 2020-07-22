
// @Title: 最小路径和 (Minimum Path Sum)
// @Author: Singularity0909
// @Date: 2020-07-23 01:35:30
// @Runtime: 8 ms
// @Memory: 8.9 MB

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        size_t n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            dp[i][0] = grid[i][0];
            if (i) dp[i][0] += dp[i - 1][0];
        }
        for (int i = 0; i < m; i++) {
            dp[0][i] = grid[0][i];
            if (i) dp[0][i] += dp[0][i - 1];
        }
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        return dp[n - 1][m - 1];
    }
};

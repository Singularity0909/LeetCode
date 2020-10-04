
// @Title: 不同路径 II (Unique Paths II)
// @Author: Singularity0909
// @Date: 2020-07-06 12:29:19
// @Runtime: 4 ms
// @Memory: 8.1 MB

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        size_t n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[1][1] = !obstacleGrid[0][0];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) continue;
                dp[i][j] = obstacleGrid[i - 1][j - 1] ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};

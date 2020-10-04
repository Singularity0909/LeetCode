
// @Title: 地下城游戏 (Dungeon Game)
// @Author: Singularity0909
// @Date: 2020-07-15 22:48:51
// @Runtime: 12 ms
// @Memory: 8.5 MB

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon)
    {
        int n = (int)dungeon.size(), m  = (int)dungeon[0].size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, INT_MAX));
        dp[n][m - 1] = dp[n - 1][m] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                dp[i][j] = max(min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};

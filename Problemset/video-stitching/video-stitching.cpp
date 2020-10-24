
// @Title: 视频拼接 (Video Stitching)
// @Author: Singularity0909
// @Date: 2020-10-24 19:34:56
// @Runtime: 4 ms
// @Memory: 7.9 MB

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T)
    {
        vector<int> dp(T + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= T; i++) {
            for (auto& it : clips) {
                if (it[0] < i && i <= it[1]) {
                    dp[i] = min(dp[i], dp[it[0]] + 1);
                }
            }
        }
        return dp[T] == INT_MAX - 1 ? -1 : dp[T];
    }
};

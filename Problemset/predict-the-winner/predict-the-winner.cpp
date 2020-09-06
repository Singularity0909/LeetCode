
// @Title: 预测赢家 (Predict the Winner)
// @Author: Singularity0909
// @Date: 2020-09-01 18:55:04
// @Runtime: 0 ms
// @Memory: 7.9 MB

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int len = (int)nums.size();
        auto dp = vector<vector<int>>(len, vector<int>(len));
        for (int i = 0; i < len; i++) {
            dp[i][i] = nums[i];
        }
        for (int i = len - 2; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][len - 1] >= 0;
    }
};

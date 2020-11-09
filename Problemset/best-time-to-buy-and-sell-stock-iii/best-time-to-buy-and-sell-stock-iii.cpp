
// @Title: 买卖股票的最佳时机 III (Best Time to Buy and Sell Stock III)
// @Author: Singularity0909
// @Date: 2020-11-08 16:33:13
// @Runtime: 636 ms
// @Memory: 132.5 MB

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        const int inf = 0x3f3f3f3f;
        size_t n = prices.size();
        vector<vector<int>> dp(n, vector<int>(6, -inf));
        dp[0][0] = 0;
        dp[0][3] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][4] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][0] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][1] - prices[i]);
            dp[i][5] = dp[i - 1][5];
        }
        return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
    }
};

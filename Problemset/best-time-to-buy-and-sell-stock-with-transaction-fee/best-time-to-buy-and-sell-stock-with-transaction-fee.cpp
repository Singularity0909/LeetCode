
// @Title: 买卖股票的最佳时机含手续费 (Best Time to Buy and Sell Stock with Transaction Fee)
// @Author: Singularity0909
// @Date: 2020-11-08 16:48:53
// @Runtime: 424 ms
// @Memory: 85.8 MB

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        size_t n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -prices[0] - fee;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
        }
        return dp[n - 1][0];
    }
};

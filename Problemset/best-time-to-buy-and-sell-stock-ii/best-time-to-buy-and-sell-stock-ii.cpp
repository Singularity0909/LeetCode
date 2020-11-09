
// @Title: 买卖股票的最佳时机 II (Best Time to Buy and Sell Stock II)
// @Author: Singularity0909
// @Date: 2020-11-08 16:19:11
// @Runtime: 20 ms
// @Memory: 9.7 MB

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        size_t n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

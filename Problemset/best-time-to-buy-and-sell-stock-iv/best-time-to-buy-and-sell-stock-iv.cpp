
// @Title: 买卖股票的最佳时机 IV (Best Time to Buy and Sell Stock IV)
// @Author: Singularity0909
// @Date: 2020-11-08 16:45:45
// @Runtime: 8 ms
// @Memory: 13 MB

class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        const int inf = 0x3f3f3f3f;
        size_t n = prices.size();
        if (not n) return 0;
        vector<vector<int>> dp0(n, vector<int>(k + 1, -inf));
        vector<vector<int>> dp1(n, vector<int>(k + 1, -inf));
        dp0[0][0] = 0;
        dp1[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp0[i][0] = dp0[i - 1][0];
            for (int j = 1; j <= k; ++j) {
                dp0[i][j] = max(dp0[i - 1][j], dp1[i - 1][j - 1] + prices[i]);
            }
            for (int j = 0; j < k; ++j) {
                dp1[i][j] = max(dp1[i - 1][j], dp0[i - 1][j] - prices[i]);
            }
            dp1[i][k] = dp1[i - 1][k];
        }
        return *max_element(dp0[n - 1].begin(), dp0[n - 1].end());
    }
};

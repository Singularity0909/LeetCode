
// @Title: 买卖股票的最佳时机 (Best Time to Buy and Sell Stock)
// @Author: Singularity0909
// @Date: 2020-07-21 19:32:19
// @Runtime: 8 ms
// @Memory: 12.4 MB

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int res = 0, mn = 0x3f3f3f3f;
        for (int x : prices) {
            res = max(res, x - mn);
            mn = min(mn, x);
        }
        return res;
    }
};

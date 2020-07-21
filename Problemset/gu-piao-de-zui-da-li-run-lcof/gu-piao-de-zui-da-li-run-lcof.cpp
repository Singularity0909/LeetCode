
// @Title: 股票的最大利润 (股票的最大利润  LCOF)
// @Author: Singularity0909
// @Date: 2020-07-21 19:31:46
// @Runtime: 12 ms
// @Memory: 13.1 MB

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

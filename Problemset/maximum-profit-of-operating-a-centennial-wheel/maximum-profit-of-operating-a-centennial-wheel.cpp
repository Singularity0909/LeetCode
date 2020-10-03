
// @Title: 经营摩天轮的最大利润 (Maximum Profit of Operating a Centennial Wheel)
// @Author: Singularity0909
// @Date: 2020-09-27 12:12:47
// @Runtime: 352 ms
// @Memory: 79.5 MB

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int n = (int)customers.size();
        int now = 0, pro = 0, mx = 0;
        int idx = -1;
        for (int i = 0; i < n || now > 0; i++) {
            if (i < n) now += customers[i];
            int x = min(4, now);
            now -= x;
            pro += boardingCost * x - runningCost;
            if (pro > mx) {
                mx = pro;
                idx = i;
            }
        }
        return mx ? idx + 1 : - 1;
    }
};

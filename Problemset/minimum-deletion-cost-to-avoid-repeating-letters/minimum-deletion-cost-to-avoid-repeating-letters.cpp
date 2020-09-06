
// @Title: 避免重复字母的最小删除成本 (Minimum Deletion Cost to Avoid Repeating Letters)
// @Author: Singularity0909
// @Date: 2020-09-06 17:13:35
// @Runtime: 432 ms
// @Memory: 95.4 MB

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        size_t n = s.length();
        char last = 0;
        int mx = 0;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            char cur = s[i];
            sum1 += cost[i];
            if (cur == last) {
                mx = max(mx, cost[i]);
            }
            else {
                sum2 += mx;
                mx = cost[i];
                last = cur;
            }
        }
        sum2 += mx;
        return sum1 - sum2;
    }
};

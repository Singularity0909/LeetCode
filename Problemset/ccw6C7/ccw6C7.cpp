
// @Title: 黑白方格画 (黑白方格画)
// @Author: Singularity0909
// @Date: 2020-09-19 20:28:56
// @Runtime: 4 ms
// @Memory: 5.8 MB

class Solution {
public:
    int paintingPlan(int n, int k) {
        map<int, int> ans;
        if (k == n * n) return 1;
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < (1 << n); j++) {
                int x = __builtin_popcount(i);
                int y = __builtin_popcount(j);
                ans[(x + y) * n - x * y]++;
            }
        }
        return ans[k];
    }
};

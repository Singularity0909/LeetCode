
// @Title: 最长重复子数组 (Maximum Length of Repeated Subarray)
// @Author: Singularity0909
// @Date: 2020-09-29 11:03:49
// @Runtime: 460 ms
// @Memory: 106.7 MB

class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        size_t n = a.size(), m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int res = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                dp[i][j] = a[i] == b[j] ? dp[i + 1][j + 1] + 1 : 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};


// @Title: 戳气球 (Burst Balloons)
// @Author: Singularity0909
// @Date: 2020-07-19 23:04:31
// @Runtime: 64 ms
// @Memory: 8.5 MB

class Solution {
public:
    vector<int> val;
    vector<vector<int>> res;
    
    int dfs(int i, int j)
    {
        if (i >= j - 1) return 0;
        if (~res[i][j]) return res[i][j];
        for (int k = i + 1; k < j; k++) {
            int sum = dfs(i, k) + val[i] * val[k] * val[j] + dfs(k, j);
            res[i][j] = max(res[i][j], sum);
        }
        return res[i][j];
    }
    
    int maxCoins(vector<int>& nums)
    {
        size_t n = nums.size();
        res.resize(n + 2, vector<int>(n + 2, -1));
        val.resize(n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <= n; i++) val[i] = nums[i - 1];
        return dfs(0, n + 1);
    }
};

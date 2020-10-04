
// @Title: 整数拆分 (Integer Break)
// @Author: Singularity0909
// @Date: 2020-07-30 00:21:14
// @Runtime: 0 ms
// @Memory: 6.1 MB

class Solution {
public:
    vector<int> ans;
    
    int integerBreak(int n) {
        ans.resize(n + 1, 0);
        if (n == 2) return 1;
        if (n == 3) return 2;
        return dfs(n);
    }
    
    int dfs(int x) {
        if (ans[x]) return ans[x];
        int res = x;
        for (int i = 1; i < x; i++)
            res = max(res, dfs(i) * dfs(x - i));
        return ans[x] = res;
    }
};

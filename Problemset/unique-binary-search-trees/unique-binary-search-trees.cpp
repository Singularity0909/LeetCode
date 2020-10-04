
// @Title: 不同的二叉搜索树 (Unique Binary Search Trees)
// @Author: Singularity0909
// @Date: 2020-07-15 02:00:29
// @Runtime: 0 ms
// @Memory: 6.1 MB

class Solution {
public:
    vector<int> res;

    int dfs(int n) {
        if (res[n]) return res[n];
        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += dfs(i - 1) * dfs(n - i);
        return res[n] = sum;
    }

    int numTrees(int n) {
        res.resize(n + 1);
        res[0] = 1;
        return dfs(n);
    }
};

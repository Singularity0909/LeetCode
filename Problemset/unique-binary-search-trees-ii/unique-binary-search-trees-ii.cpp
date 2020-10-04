
// @Title: 不同的二叉搜索树 II (Unique Binary Search Trees II)
// @Author: Singularity0909
// @Date: 2020-07-21 00:54:10
// @Runtime: 20 ms
// @Memory: 14.4 MB

class Solution {
public:
    vector<TreeNode*> dfs(int left, int right)
    {
        if (left > right) return { nullptr };
        vector<TreeNode*> res, lson, rson;
        for (int i = left; i <= right; i++) {
            lson = dfs(left, i - 1);
            rson = dfs(i + 1, right);
            for (auto& l : lson) {
                for (auto& r : rson) {
                    res.emplace_back(new TreeNode(i, l, r));
                }
            }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n)
    {
        if (n == 0) return {};
        return dfs(1, n);
    }
};

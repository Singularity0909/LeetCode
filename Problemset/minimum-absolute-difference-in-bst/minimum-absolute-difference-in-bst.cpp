
// @Title: 二叉搜索树的最小绝对差 (Minimum Absolute Difference in BST)
// @Author: Singularity0909
// @Date: 2020-10-12 09:57:52
// @Runtime: 24 ms
// @Memory: 24.4 MB

class Solution {
public:
    void dfs(TreeNode* cur, int& ans, int& pre)
    {
        if (!cur) return;
        dfs(cur->left, ans, pre);
        ans = min(ans, abs(pre - cur->val));
        pre = cur->val;
        dfs(cur->right, ans, pre);
    }

    int getMinimumDifference(TreeNode* root) {
        int inf(0x3f3f3f3f);
        int ans = inf;
        dfs(root, ans, inf);
        return ans;
    }
};

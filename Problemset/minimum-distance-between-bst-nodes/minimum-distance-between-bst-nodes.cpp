
// @Title: 二叉搜索树节点最小距离 (Minimum Distance Between BST Nodes)
// @Author: Singularity0909
// @Date: 2020-10-12 10:01:03
// @Runtime: 4 ms
// @Memory: 9.6 MB

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

    int minDiffInBST(TreeNode* root) {
        int inf(0x3f3f3f3f);
        int ans = inf;
        dfs(root, ans, inf);
        return ans;
    }
};

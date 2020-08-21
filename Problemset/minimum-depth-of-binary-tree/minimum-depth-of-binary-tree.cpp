
// @Title: 二叉树的最小深度 (Minimum Depth of Binary Tree)
// @Author: Singularity0909
// @Date: 2020-08-21 08:40:20
// @Runtime: 12 ms
// @Memory: 17.7 MB

class Solution {
public:
    int dfs(TreeNode* root) {
        if (!root) return 0x3f3f3f3f;
        if (!root->left && !root->right) return 1;
        return min(dfs(root->left), dfs(root->right)) + 1;
    }

    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return dfs(root);
    }
};

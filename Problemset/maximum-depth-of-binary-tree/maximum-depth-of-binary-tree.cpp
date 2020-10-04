
// @Title: 二叉树的最大深度 (Maximum Depth of Binary Tree)
// @Author: Singularity0909
// @Date: 2020-07-28 00:08:15
// @Runtime: 12 ms
// @Memory: 16.7 MB

class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

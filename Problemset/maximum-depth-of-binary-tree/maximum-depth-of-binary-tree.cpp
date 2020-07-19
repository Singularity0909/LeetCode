
// @Title: 二叉树的最大深度 (Maximum Depth of Binary Tree)
// @Author: Singularity0909
// @Date: 2020-07-20 02:09:12
// @Runtime: 12 ms
// @Memory: 17.1 MB

class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

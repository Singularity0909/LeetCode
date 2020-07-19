
// @Title: 二叉树的深度 (二叉树的深度 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-20 02:08:11
// @Runtime: 4 ms
// @Memory: 19.2 MB

class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};


// @Title: 平衡二叉树 (Balanced Binary Tree)
// @Author: Singularity0909
// @Date: 2020-08-17 00:05:47
// @Runtime: 12 ms
// @Memory: 14 MB

class Solution {
public:
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (!isBalanced(root->left) || !isBalanced(root->right)) return false;
        int dep_left = getDepth(root->left), dep_right = getDepth(root->right);
        return abs(dep_left - dep_right) <= 1;
    }
};

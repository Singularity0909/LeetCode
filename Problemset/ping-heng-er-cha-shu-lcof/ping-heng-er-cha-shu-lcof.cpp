
// @Title: 平衡二叉树 (平衡二叉树 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-06 13:17:01
// @Runtime: 16 ms
// @Memory: 21.5 MB

class Solution {
public:
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(getDepth(root->left) - getDepth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};


// @Title: 对称的二叉树 (对称的二叉树  LCOF)
// @Author: Singularity0909
// @Date: 2020-07-06 01:14:01
// @Runtime: 8 ms
// @Memory: 15.8 MB

class Solution {
public:
    bool equal(TreeNode* a, TreeNode* b) {
        if (!a) return !b;
        if (!b) return !a;
        if (a->val != b->val) return false;
        return equal(a->left, b->right) && equal(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {
        return !root || equal(root->left, root->right);
    }
};

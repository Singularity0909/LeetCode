
// @Title: 对称二叉树 (Symmetric Tree)
// @Author: Singularity0909
// @Date: 2020-07-06 01:13:21
// @Runtime: 12 ms
// @Memory: 12 MB

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

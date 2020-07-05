
// @Title: 对称的二叉树 (对称的二叉树  LCOF)
// @Author: Singularity0909
// @Date: 2020-07-05 22:41:22
// @Runtime: 4 ms
// @Memory: 16.5 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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

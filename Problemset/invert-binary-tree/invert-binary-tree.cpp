
// @Title: 翻转二叉树 (Invert Binary Tree)
// @Author: Singularity0909
// @Date: 2020-09-16 00:35:30
// @Runtime: 0 ms
// @Memory: 9.1 MB

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

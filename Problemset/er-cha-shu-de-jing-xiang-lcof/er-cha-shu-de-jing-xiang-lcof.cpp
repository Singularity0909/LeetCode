
// @Title: 二叉树的镜像 (二叉树的镜像  LCOF)
// @Author: Singularity0909
// @Date: 2020-07-05 22:32:14
// @Runtime: 0 ms
// @Memory: 9.2 MB

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
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return nullptr;
        root->left = mirrorTree(root->left);
        root->right = mirrorTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};


// @Title: 二叉树的镜像 (二叉树的镜像  LCOF)
// @Author: Singularity0909
// @Date: 2020-07-06 01:14:23
// @Runtime: 4 ms
// @Memory: 9.2 MB

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

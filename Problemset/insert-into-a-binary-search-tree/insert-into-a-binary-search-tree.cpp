
// @Title: 二叉搜索树中的插入操作 (Insert into a Binary Search Tree)
// @Author: Singularity0909
// @Date: 2020-09-30 09:46:49
// @Runtime: 172 ms
// @Memory: 56.2 MB

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        TreeNode* cur = root;
        while (true) {
            if (val <= cur->val) {
                if (cur->left) {
                    cur = cur->left;
                } else {
                    cur->left = new TreeNode(val);
                    break;
                }
            } else {
                if (cur->right) {
                    cur = cur->right;
                } else {
                    cur->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};


// @Title: 把二叉搜索树转换为累加树 (Convert BST to Greater Tree)
// @Author: Singularity0909
// @Date: 2020-09-21 08:36:50
// @Runtime: 68 ms
// @Memory: 32.5 MB

class Solution {
public:
    int sum = 0;
    
    TreeNode* convertBST(TreeNode* root) {
        if (root != nullptr) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};


// @Title: 从二叉搜索树到更大和树 (Binary Search Tree to Greater Sum Tree)
// @Author: Singularity0909
// @Date: 2020-09-21 08:37:22
// @Runtime: 4 ms
// @Memory: 8.1 MB

class Solution {
public:
    int sum = 0;
    
    TreeNode* bstToGst(TreeNode* root) {
        if (root != nullptr) {
            bstToGst(root->right);
            sum += root->val;
            root->val = sum;
            bstToGst(root->left);
        }
        return root;
    }
};

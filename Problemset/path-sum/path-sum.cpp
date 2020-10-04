
// @Title: 路径总和 (Path Sum)
// @Author: Singularity0909
// @Date: 2020-07-07 01:06:57
// @Runtime: 12 ms
// @Memory: 16.9 MB

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return root->val == sum;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

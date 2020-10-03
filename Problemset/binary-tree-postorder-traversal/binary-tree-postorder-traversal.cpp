
// @Title: 二叉树的后序遍历 (Binary Tree Postorder Traversal)
// @Author: Singularity0909
// @Date: 2020-09-29 01:54:42
// @Runtime: 0 ms
// @Memory: 8.4 MB

class Solution {
public:
    vector<int> res;

    void dfs(TreeNode* cur) {
        if (!cur) return;
        dfs(cur->left);
        dfs(cur->right);
        res.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};

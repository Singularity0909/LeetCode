
// @Title: 二叉树的中序遍历 (Binary Tree Inorder Traversal)
// @Author: Singularity0909
// @Date: 2020-09-14 08:40:32
// @Runtime: 0 ms
// @Memory: 7.1 MB

class Solution {
public:
    vector<int> res;

    void dfs(TreeNode* cur) {
        if (!cur) return;
        dfs(cur->left);
        res.push_back(cur->val);
        dfs(cur->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};

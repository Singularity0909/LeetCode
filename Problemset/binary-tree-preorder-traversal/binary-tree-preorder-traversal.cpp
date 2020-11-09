
// @Title: 二叉树的前序遍历 (Binary Tree Preorder Traversal)
// @Author: Singularity0909
// @Date: 2020-10-27 16:28:50
// @Runtime: 0 ms
// @Memory: 8.5 MB

class Solution {
public:
    void dfs(const TreeNode* cur, vector<int>& vec) {
        if (not cur) return;
        vec.push_back(cur->val);
        dfs(cur->left, vec);
        dfs(cur->right, vec);
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};

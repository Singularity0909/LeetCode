
// @Title: 二叉树的所有路径 (Binary Tree Paths)
// @Author: Singularity0909
// @Date: 2020-09-04 01:39:00
// @Runtime: 4 ms
// @Memory: 14.1 MB

class Solution {
public:
    void dfs(TreeNode* cur, string str, vector<string>& res) {
        if (!cur) return;
        str += to_string(cur->val);
        if (!cur->left && !cur->right) {
            res.push_back(str);
            return;
        }
        str += "->";
        dfs(cur->left, str, res);
        dfs(cur->right, str, res);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
};

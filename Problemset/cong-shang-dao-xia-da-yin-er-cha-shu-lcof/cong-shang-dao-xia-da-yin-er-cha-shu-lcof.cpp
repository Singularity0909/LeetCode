
// @Title: 从上到下打印二叉树 (从上到下打印二叉树 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-21 20:26:09
// @Runtime: 4 ms
// @Memory: 12.3 MB

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* now = q.front();
            q.pop();
            res.push_back(now->val);
            if (now->left) q.push(now->left);
            if (now->right) q.push(now->right);
        }
        return res;
    }
};

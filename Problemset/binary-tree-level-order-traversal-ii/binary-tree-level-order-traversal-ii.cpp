
// @Title: 二叉树的层次遍历 II (Binary Tree Level Order Traversal II)
// @Author: Singularity0909
// @Date: 2020-09-06 01:26:39
// @Runtime: 4 ms
// @Memory: 11.8 MB

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        vector<int> tmp;
        using p = pair<TreeNode*, int>;
        queue<p> q;
        q.push(p(root, 0));
        int last = 0;
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int dep = q.front().second;
            q.pop();
            if (dep != last) {
                res.push_back(tmp);
                tmp.clear();
            }
            tmp.push_back(cur->val);
            last = dep;
            if (cur->left) {
                q.push(p(cur->left, dep + 1));
            }
            if (cur->right) {
                q.push(p(cur->right, dep + 1));
            }
        }
        if (!tmp.empty()) {
            res.push_back(tmp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

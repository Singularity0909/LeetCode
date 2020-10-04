
// @Title: 从上到下打印二叉树 II (从上到下打印二叉树 II LCOF)
// @Author: Singularity0909
// @Date: 2020-07-21 02:23:10
// @Runtime: 12 ms
// @Memory: 12.4 MB

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        using p = pair<int, TreeNode*>;
        queue<p> q;
        q.push(p(0, root));
        vector<vector<int>> res;
        vector<int> tmp;
        int last = 0;
        while (!q.empty()) {
            int dep = q.front().first;
            TreeNode* now = q.front().second;
            q.pop();
            if (dep != last) {
                last = dep;
                res.push_back(tmp);
                tmp.clear();
            }
            tmp.push_back(now->val);
            if (now->left) q.push(p(dep + 1, now->left));
            if (now->right) q.push(p(dep + 1, now->right));
        }
        res.push_back(tmp);
        return res;
    }
};

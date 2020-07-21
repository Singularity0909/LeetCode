
// @Title: 从上到下打印二叉树 III (从上到下打印二叉树 III LCOF)
// @Author: Singularity0909
// @Date: 2020-07-22 00:34:22
// @Runtime: 4 ms
// @Memory: 12.8 MB

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        using p = pair<int, TreeNode*>;
        if (!root) return {};
        queue<p> q;
        q.push(p(0, root));
        vector<int> level;
        vector<vector<int>> all;
        int last = 0;
        while (!q.empty()) {
            int dep = q.front().first;
            TreeNode* now = q.front().second;
            q.pop();
            if (dep != last) {
                all.push_back(level);
                level.clear();
                last = dep;
            }
            if (dep & 1) level.insert(level.begin(), now->val);
            else level.push_back(now->val);
            if (now->left) q.push(p(dep + 1, now->left));
            if (now->right) q.push(p(dep + 1, now->right));
        }
        if (!level.empty()) all.push_back(level);
        return all;
    }
};

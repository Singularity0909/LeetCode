
// @Title: 二叉树的层平均值 (Average of Levels in Binary Tree)
// @Author: Singularity0909
// @Date: 2020-09-12 01:15:47
// @Runtime: 24 ms
// @Memory: 22.8 MB

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        using p = pair<TreeNode*, int>;
        vector<double> res;
        double sum = 0;
        int last_dep = 0, cnt = 0;
        queue<p> q;
        q.push(p(root, 0));
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int cur_dep = q.front().second;
            q.pop();
            if (cur_dep == last_dep) {
                cnt++;
                sum += cur->val;
            }
            else {
                res.push_back(sum / cnt);
                cnt = 1;
                sum = cur->val;
                last_dep = cur_dep;
            }
            if (cur->left) q.push(p(cur->left, cur_dep + 1));
            if (cur->right) q.push(p(cur->right, cur_dep + 1));
        }
        if (cnt) res.push_back(sum / cnt);
        return res;
    }
};

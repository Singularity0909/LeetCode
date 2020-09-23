
// @Title: 二叉搜索树中的众数 (Find Mode in Binary Search Tree)
// @Author: Singularity0909
// @Date: 2020-09-24 01:31:34
// @Runtime: 36 ms
// @Memory: 29.5 MB

class Solution {
public:
    using p = pair<int, int>;
    unordered_map<int, int> mp;

    void dfs(TreeNode* cur) {
        if (!cur) return;
        dfs(cur->left);
        dfs(cur->right);
        mp[cur->val]++;
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        vector<p> vec;
        int mx = 0;
        for (auto& each : mp) {
            mx = max(mx, each.second);
            if (vec.empty() || vec.front().second == each.second) {
                vec.push_back(p(each.first, mx));
            }
            else if (each.second > vec.front().second) {
                vec.clear();
                vec.push_back(p(each.first, mx));
            }
        }
        vector<int> res;
        for (auto& each : vec) res.push_back(each.first);
        return res;
    }
};

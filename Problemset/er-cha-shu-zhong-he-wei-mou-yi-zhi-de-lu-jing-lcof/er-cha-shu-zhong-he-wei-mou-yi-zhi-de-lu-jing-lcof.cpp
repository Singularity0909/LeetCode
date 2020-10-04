
// @Title: 二叉树中和为某一值的路径 (二叉树中和为某一值的路径 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-29 19:57:10
// @Runtime: 8 ms
// @Memory: 22.4 MB

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return {};
        if (!root->left && !root->right && root->val == sum) {
            return { { root->val } };
        }
        auto ls = pathSum(root->left, sum - root->val);
        auto rs = pathSum(root->right, sum - root->val);
        if (!ls.empty()) {
            for (auto& each : ls) {
                each.insert(each.begin(), root->val);
            }
        }
        if (!rs.empty()) {
            for (auto& each : rs) {
                each.insert(each.begin(), root->val);
                ls.push_back(each);
            }
        }
        return ls;
    }
};

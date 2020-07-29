
// @Title: 路径总和 II (Path Sum II)
// @Author: Singularity0909
// @Date: 2020-07-29 19:56:30
// @Runtime: 16 ms
// @Memory: 19.7 MB

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

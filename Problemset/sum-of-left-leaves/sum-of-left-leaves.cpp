
// @Title: 左叶子之和 (Sum of Left Leaves)
// @Author: Singularity0909
// @Date: 2020-09-19 09:00:59
// @Runtime: 4 ms
// @Memory: 13.3 MB

class Solution {
public:
    int dfs(TreeNode* now, bool left) {
        if (!now) return 0;
        if (!now->left && !now->right) {
            return left ? now->val : 0;
        }
        return dfs(now->left, true) + dfs(now->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};

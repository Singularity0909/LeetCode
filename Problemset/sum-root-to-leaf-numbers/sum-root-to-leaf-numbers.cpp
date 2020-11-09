
// @Title: 求根到叶子节点数字之和 (Sum Root to Leaf Numbers)
// @Author: Singularity0909
// @Date: 2020-10-29 10:26:19
// @Runtime: 0 ms
// @Memory: 12.4 MB

class Solution {
public:
    void dfs(TreeNode* cur, int sum, int& ans)
    {
        sum = sum * 10 + cur->val;
        if (not cur->left and not cur->right) {
            ans += sum;
            return;
        }
        if (cur->left) {
            dfs(cur->left, sum, ans);
        }
        if (cur->right) {
            dfs(cur->right, sum, ans);
        }
    }

    int sumNumbers(TreeNode* root)
    {
        if (not root) {
            return 0;
        }
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
};

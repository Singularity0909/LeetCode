
// @Title: 打家劫舍 III (House Robber III)
// @Author: Singularity0909
// @Date: 2020-08-08 13:58:01
// @Runtime: 40 ms
// @Memory: 29.4 MB

class Solution {
public:
    unordered_map<TreeNode*, int> m1, m2;
    
    void dfs(TreeNode* now) {
        if (!now) return;
        dfs(now->left);
        dfs(now->right);
        m1[now] = now->val + m2[now->left] + m2[now->right];
        m2[now] = max(m1[now->left], m2[now->left]) + max(m1[now->right], m2[now->right]);
    }
    
    int rob(TreeNode* root) {
        dfs(root);
        return max(m1[root], m2[root]);
    }
};

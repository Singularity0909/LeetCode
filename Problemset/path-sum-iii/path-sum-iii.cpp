
// @Title: 路径总和 III (Path Sum III)
// @Author: Singularity0909
// @Date: 2020-07-07 02:47:10
// @Runtime: 28 ms
// @Memory: 15.2 MB

class Solution {
public:
    int cnt = 0;
    
    void dfs(TreeNode* root, int now, int tar) {
        if (!root) return;
        if ((now += root->val) == tar) cnt++;
        dfs(root->left, now, tar);
        dfs(root->right, now, tar);
    }

    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        dfs(root, 0, sum);
        return cnt;
    }
};

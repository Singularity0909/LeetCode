
// @Title: 监控二叉树 (Binary Tree Cameras)
// @Author: Singularity0909
// @Date: 2020-09-22 04:19:45
// @Runtime: 36 ms
// @Memory: 25.5 MB

class Solution {
public:
    const int inf = 0x3f3f3f3f;
    unordered_map<TreeNode*, vector<int>> mp;
    
    void dfs(TreeNode* cur) {
        mp[cur].resize(3, 0);
        if (!cur) {
            mp[cur][0] = inf;
            return;
        }
        dfs(cur->left);
        dfs(cur->right);
        mp[cur][0] = mp[cur->left][2] + mp[cur->right][2] + 1;
        mp[cur][1] = min(mp[cur][0], mp[cur->left][0] + mp[cur->right][1]);
        mp[cur][1] = min(mp[cur][1], mp[cur->right][0] + mp[cur->left][1]);
        mp[cur][2] = min(mp[cur][0], mp[cur->left][1] + mp[cur->right][1]);
    }
    
    int minCameraCover(TreeNode* root) {
        dfs(root);
        return mp[root][1];
    }
};

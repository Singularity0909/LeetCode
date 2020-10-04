
// @Title: 好叶子节点对的数量 (Number of Good Leaf Nodes Pairs)
// @Author: Singularity0909
// @Date: 2020-07-26 21:03:42
// @Runtime: 188 ms
// @Memory: 36.7 MB

class Solution {
public:
    vector<int> dfs(TreeNode* tree, int distance, int& ans) {
        if (!tree->left && !tree->right) return { 1 };
        vector<int> now, ls, rs;
        if (tree->left) ls = dfs(tree->left, distance, ans);
        if (tree->right) rs = dfs(tree->right, distance, ans);
        for (int i : ls) for (int j : rs) if (i + j <= distance) ans++;
        for (int x : ls) now.push_back(x + 1);
        for (int x : rs) now.push_back(x + 1);
        return now;
    }
    
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }
};

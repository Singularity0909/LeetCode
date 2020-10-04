
// @Title: 二叉搜索树的第k大节点 (二叉搜索树的第k大节点  LCOF)
// @Author: Singularity0909
// @Date: 2020-08-04 19:56:20
// @Runtime: 28 ms
// @Memory: 23.4 MB

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int cnt = 0;
        return dfs(root, cnt, k);
    }
    
    int dfs(TreeNode* now, int& cnt, int k) {
        int res = 0;
        if (now->right && (res = dfs(now->right, cnt, k))) {
            return res;
        }
        if (++cnt == k) return now->val;
        if (now->left && (res = dfs(now->left, cnt, k))) {
            return  res;
        }
        return 0;
    }
};


// @Title: 二叉搜索树的后序遍历序列 (二叉搜索树的后序遍历序列 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-29 19:43:41
// @Runtime: 0 ms
// @Memory: 7 MB

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return dfs(postorder, 0, (int)postorder.size() - 1);
    }
    
    bool dfs(vector<int>& postorder, int l, int r) {
        if (l >= r) return true;
        int root = postorder[r];
        int pos = r;
        for (int i = l; i < r; i++) {
            if (postorder[i] > root && pos == r) pos = i;
            if (postorder[i] < root && pos != r) return false;
        }
        return dfs(postorder, l, pos - 1) && dfs(postorder, pos, r - 1);
    }
};

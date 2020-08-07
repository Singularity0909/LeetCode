
// @Title: 相同的树 (Same Tree)
// @Author: Singularity0909
// @Date: 2020-08-07 00:34:51
// @Runtime: 0 ms
// @Memory: 10.1 MB

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return !p && !q;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

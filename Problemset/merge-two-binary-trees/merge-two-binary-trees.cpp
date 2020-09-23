
// @Title: 合并二叉树 (Merge Two Binary Trees)
// @Author: Singularity0909
// @Date: 2020-09-23 08:39:31
// @Runtime: 80 ms
// @Memory: 32.2 MB

class Solution {
public:
    TreeNode * mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};

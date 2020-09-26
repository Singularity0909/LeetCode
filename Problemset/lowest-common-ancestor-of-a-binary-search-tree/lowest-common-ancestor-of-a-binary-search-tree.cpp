
// @Title: 二叉搜索树的最近公共祖先 (Lowest Common Ancestor of a Binary Search Tree)
// @Author: Singularity0909
// @Date: 2020-09-27 02:37:28
// @Runtime: 36 ms
// @Memory: 23.1 MB

class Solution {
public:
    inline bool get(TreeNode* cur, TreeNode* tar) {
        if (!cur) return false;
        if (cur->val == tar->val) return true;
        return get(cur->left, tar) || get(cur->right, tar);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool left1 = get(root->left, p);
        bool left2 = get(root->left, q);
        bool right1 = get(root->right, p);
        bool right2 = get(root->right, q);
        if (left1 && left2) return lowestCommonAncestor(root->left, p, q);
        if (right1 && right2) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};


// @Title: 合并二叉树 (Merge Two Binary Trees)
// @Author: Singularity0909
// @Date: 2020-09-23 08:08:08
// @Runtime: 80 ms
// @Memory: 33.5 MB

class Solution {
public:
    void dfs(TreeNode*& newTree, TreeNode* orgTree) {
        if (!orgTree) return;
        if (newTree == nullptr) newTree = new TreeNode(orgTree->val);
        else newTree->val += orgTree->val;
        dfs(newTree->left, orgTree->left);
        dfs(newTree->right, orgTree->right);
    }

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* root = nullptr;
        dfs(root, t1);
        dfs(root, t2);
        return root;
    }
};

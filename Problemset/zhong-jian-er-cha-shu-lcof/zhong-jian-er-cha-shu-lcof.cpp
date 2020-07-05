
// @Title: 重建二叉树 (重建二叉树 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-06 01:21:27
// @Runtime: 28 ms
// @Memory: 25.9 MB

class Solution {
public:
    unordered_map<int, int> pos_in;

    TreeNode* build(vector<int>& pre, vector<int>& in, int left_pre, int right_pre, int left_in, int right_in) {
        int val_root = pre[left_pre];
        TreeNode* now = new TreeNode(val_root);
        int pos = pos_in[val_root];
        if (pos > left_in)
            now->left = build(pre, in, left_pre + 1, left_pre + pos - left_in, left_in, pos - 1);
        if (pos < right_in)
            now->right = build(pre, in, left_pre + pos - left_in + 1, right_pre, pos + 1, right_in);
        return now;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < (int)inorder.size(); i++)
            pos_in[inorder[i]] = i;
        if (preorder.empty())
            return nullptr;
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};

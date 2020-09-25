
// @Title: 从中序与后序遍历序列构造二叉树 (Construct Binary Tree from Inorder and Postorder Traversal)
// @Author: Singularity0909
// @Date: 2020-09-25 11:09:40
// @Runtime: 20 ms
// @Memory: 17.7 MB

class Solution {
public:
    unordered_map<int, int> mp;
    
    TreeNode* build(vector<int>& in, vector<int>& post, int il, int ir, int pl, int pr) {
        if (il > ir) return nullptr;
        int val_root = post[pr];
        TreeNode* cur = new TreeNode(val_root);
        int pos = mp[val_root];
        int nl = pos - il;
        cur->left = build(in, post, il, pos - 1, pl, pl + nl - 1);
        cur->right = build(in, post, pos + 1, ir, pl + nl, pr - 1);
        return cur;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < (int)inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, (int)inorder.size() - 1, 0, (int)postorder.size() - 1);
    }
};

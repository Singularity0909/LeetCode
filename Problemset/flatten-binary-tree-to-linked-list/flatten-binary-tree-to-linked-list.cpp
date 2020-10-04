
// @Title: 二叉树展开为链表 (Flatten Binary Tree to Linked List)
// @Author: Singularity0909
// @Date: 2020-08-02 23:47:41
// @Runtime: 8 ms
// @Memory: 11.7 MB

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                auto next = cur->left;
                auto pre = next;
                while (pre->right) pre = pre->right;
                pre->right = cur->right;
                cur->left = nullptr;
                cur->right = next;
            }
            cur = cur->right;
        }
    }
};

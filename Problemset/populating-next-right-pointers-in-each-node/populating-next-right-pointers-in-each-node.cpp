
// @Title: 填充每个节点的下一个右侧节点指针 (Populating Next Right Pointers in Each Node)
// @Author: Singularity0909
// @Date: 2020-10-15 00:15:52
// @Runtime: 28 ms
// @Memory: 16.8 MB

class Solution {
public:
    void dfs(Node* cur, Node* pre)
    {
        if (not cur) {
            return;
        }
        if (cur == pre->left) {
            cur->next = pre->right;
        } else if (cur == pre->right) {
            cur->next = pre->next ? pre->next->left : nullptr;
        } else {
            cur->next = nullptr;
        }
        dfs(cur->left, cur);
        dfs(cur->right, cur);
    }
    
    Node* connect(Node* root)
    {
        dfs(root, root);
        return root;
    }
};

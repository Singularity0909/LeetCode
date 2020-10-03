
// @Title: 填充每个节点的下一个右侧节点指针 II (Populating Next Right Pointers in Each Node II)
// @Author: Singularity0909
// @Date: 2020-09-28 01:23:56
// @Runtime: 20 ms
// @Memory: 17.4 MB

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        using p = pair<Node*, int>;
        queue<p> q;
        q.push(p(root, 0));
        while (!q.empty()) {
            Node* cur = q.front().first;
            int dep = q.front().second;
            q.pop();
            if (!q.empty() and dep == q.front().second) {
                cur->next = q.front().first;
            } else {
                cur->next = nullptr;
            }
            if (cur->left) {
                q.push(p(cur->left, dep + 1));
            }
            if (cur->right) {
                q.push(p(cur->right, dep + 1));
            }
        }
        return root;
    }
};

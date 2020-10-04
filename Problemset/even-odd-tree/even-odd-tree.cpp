
// @Title: 奇偶树 (Even Odd Tree)
// @Author: Singularity0909
// @Date: 2020-10-05 01:04:20
// @Runtime: 492 ms
// @Memory: 150.5 MB

class Solution {
public:
    bool isEvenOddTree(TreeNode* root)
    {
        using p = pair<TreeNode*, int>;
        queue<p> q;
        q.push(p(root, 0));
        int val_last = 0;
        int dep_last = -1;
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int val_cur = cur->val;
            int dep_cur = q.front().second;
            q.pop();
            if ((dep_cur & 1) and (val_cur & 1)) {
                return false;
            }
            if (not (dep_cur & 1) and not (val_cur & 1)) {
                return false;
            }
            if (dep_cur != dep_last) {
                dep_last = dep_cur;
            } else if (dep_cur & 1) {
                if (val_cur >= val_last) {
                    return false;
                }
            } else if (val_cur <= val_last) {
                return false;
            }
            val_last = val_cur;
            if (cur->left) {
                q.push(p(cur->left, dep_cur + 1));
            }
            if (cur->right) {
                q.push(p(cur->right, dep_cur + 1));
            }
        }
        return true;
    }
};

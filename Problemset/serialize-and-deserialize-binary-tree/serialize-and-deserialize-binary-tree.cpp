
// @Title: 二叉树的序列化与反序列化 (Serialize and Deserialize Binary Tree)
// @Author: Singularity0909
// @Date: 2020-09-27 02:24:15
// @Runtime: 76 ms
// @Memory: 32.2 MB

class Codec {
public:
    vector<string> split(const string& s, const string& sep) {
        vector<string> res;
        string::size_type pos1, pos2;
        pos2 = s.find(sep);
        pos1 = 0;
        while (string::npos != pos2) {
            res.push_back(s.substr(pos1, pos2 - pos1));
            pos1 = pos2 + sep.size();
            pos2 = s.find(sep, pos1);
        }
        if (pos1 != s.length()) res.push_back(s.substr(pos1));
        return res;
    }

    string serialize(TreeNode* root) {
        using p = pair<TreeNode*, int>;
        queue<p> q;
        q.push(p(root, 0));
        string res = "[";
        vector<bool> vis(1000, false);
        vis[0] = true;
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int dep = q.front().second;
            q.pop();
            if (cur) {
                res += to_string(cur->val) + ",";
                if (cur->left || cur->right) vis[dep + 1] = true;
                q.push(p(cur->left, dep + 1));
                q.push(p(cur->right, dep + 1));
            }
            else if (vis[dep]) res += "null,";
        }
        res.pop_back();
        res.push_back(']');
        return res;
    }

    TreeNode* deserialize(string data) {
        data.erase(0, 1);
        data.pop_back();
        vector<string> str = split(data, ",");
        vector<TreeNode*> tree;
        for (const string& each : str) {
            if (each == "null") tree.push_back(nullptr);
            else tree.push_back(new TreeNode(stoi(each)));
        }
        for (int i = 0, j = 1; j < (int)tree.size(); i++) {
            if (!tree[i]) continue;
            if (j < (int)tree.size()) tree[i]->left = tree[j++];
            if (j < (int)tree.size()) tree[i]->right = tree[j++];
        }
        return tree[0];
    }
};


// @Title: 子树中标签相同的节点数 (Number of Nodes in the Sub-Tree With the Same Label)
// @Author: Singularity0909
// @Date: 2020-07-27 01:04:10
// @Runtime: 1256 ms
// @Memory: 230.8 MB

class Solution {
public:
    vector<vector<int>> son;
    vector<bool> vis;
    vector<vector<int>> label;
    string* labels;
    
    void dfs(int now)
    {
        vis[now] = true;
        label[now][(*labels)[now] - 'a']++;
        for (int nxt : son[now]) {
            if (vis[nxt]) continue;
            dfs(nxt);
            for (int i = 0; i < 26; i++) {
                label[now][i] += label[nxt][i];
            }
        }
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)
    {
        this->labels = &labels;
        son.resize(n);
        vis.resize(n);
        label.resize(n, vector<int>(26, 0));
        for (vector<int> edge : edges) {
            int a = edge[0], b = edge[1];
            son[a].push_back(b);
            son[b].push_back(a);
        }
        dfs(0);
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = label[i][labels[i] - 'a'];
        }
        return res;
    }
};

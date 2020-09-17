
// @Title: 冗余连接 II (Redundant Connection II)
// @Author: Singularity0909
// @Date: 2020-09-17 17:35:13
// @Runtime: 60 ms
// @Memory: 45.6 MB

class Solution {
public:
    bool judge(vector<vector<int>>& edges, vector<vector<int>>& nxt, vector<int> indeg, vector<int> exp) {
        int cnt = 0, n = edges.size();
        vector<bool> vis(n + 1, false);
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (!indeg[i]) {
                if (!q.empty()) return false;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (vis[u]) return false;
            vis[u] = true;
            for (int v : nxt[u]) {
                if (exp.front() == u && exp.back() == v) continue;
                cnt++;
                if (!--indeg[v]) q.push(v);
            }
        }
        return cnt + 1 == n;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> res;
        int n = edges.size();
        vector<vector<int>> nxt(n + 1);
        vector<int> indeg(n + 1, 0);
        for (auto& edge : edges) {
            int u = edge.front(), v = edge.back();
            indeg[v]++;
            nxt[u].push_back(v);
        }
        for (auto& edge : edges) {
            indeg[edge.back()]--;
            if (judge(edges, nxt, indeg, edge)) {
                res.clear();
                res.push_back(edge.front());
                res.push_back(edge.back());
            }
            indeg[edge.back()]++;
        }
        return res;
    }
};

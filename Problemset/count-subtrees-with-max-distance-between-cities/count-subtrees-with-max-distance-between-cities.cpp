
// @Title: 统计子树中城市之间最大距离 (Count Subtrees With Max Distance Between Cities)
// @Author: Singularity0909
// @Date: 2020-10-11 20:34:22
// @Runtime: 836 ms
// @Memory: 278.6 MB

class Solution {
public:
    void floyd(vector<vector<int>>& dis)
    {
        int n = (int)dis.size();
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
    
    bool isConnected(const vector<int>& vec, const vector<vector<int>>& son)
    {
        int n = (int)son.size();
        vector<bool> vis(n, false);
        vector<bool> in(n, false);
        for (int x : vec) in[x] = true;
        queue<int> q;
        q.push(vec.front());
        vis[vec.front()] = true;
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ++cnt;
            for (int v : son[u]) {
                if (!vis[v] and in[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        return vec.size() == cnt;
    }
    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges)
    {
        static const int inf = 0x3f3f3f3f;
        vector<int> ans(n - 1, 0);
        vector<vector<int>> dis(n, vector<int>(n, inf));
        vector<vector<int>> son(n);
        for (int i = 0; i < n; ++i) {
            dis[i][i] = 0;
        }
        for (auto& edge : edges) {
            int u = edge.front() - 1, v = edge.back() - 1;
            dis[u][v] = dis[v][u] = 1;
            son[u].push_back(v);
            son[v].push_back(u);
        }
        floyd(dis);
        vector<int> vec;
        for (int i = 1; i < (1 << n); ++i) {
            vec.clear();
            int cnt = 0, now = i;
            while (now) {
                if (now & 1) {
                    vec.push_back(cnt);
                }
                now >>= 1;
                ++cnt;
            }
            int m = (int)vec.size(), mx = 0;
            if (!isConnected(vec, son)) {
                continue;
            }
            for (int j = 0; j < m; ++j) {
                for (int k = j + 1; k < m; ++k) {
                    mx = max(mx, dis[vec[j]][vec[k]]);
                }
            }
            if (mx) {
                ++ans[mx - 1];
            }
        }
        return ans;
    }
};

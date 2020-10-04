
// @Title: 判断二分图 (Is Graph Bipartite?)
// @Author: Singularity0909
// @Date: 2020-07-16 01:34:23
// @Runtime: 36 ms
// @Memory: 11.5 MB

class Solution {
public:
    bool dfs(int now, int pre, vector<int>& color, vector<vector<int>>& graph, vector<bool>& vis) {
        vis[now] = true;
        if (now == pre) color[now] = 0;
        else color[now] = color[pre] ^ 1;
        for (int nxt : graph[now]) {
            if (!vis[nxt] && !dfs(nxt, now, color, graph, vis)) return false;
            else if (color[now] == color[nxt]) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        vector<bool> vis(graph.size(), false);
        for (int i = 0; i < graph.size(); i++) {
            if (!vis[i] && !dfs(i, i, color, graph, vis)) {
                return false;
            }
        }
        return true;
    }
};

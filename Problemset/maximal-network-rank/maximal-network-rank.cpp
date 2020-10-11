
// @Title: 最大网络秩 (Maximal Network Rank)
// @Author: Singularity0909
// @Date: 2020-10-11 10:41:44
// @Runtime: 200 ms
// @Memory: 32.6 MB

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads)
    {
        vector<vector<int>> edges(n);
        vector<vector<int>> cnt(n, vector<int>(n, 0));
        for (auto& road : roads) {
            int u = road.front(), v = road.back();
            edges[u].push_back(v);
            edges[v].push_back(u);
            ++cnt[u][v];
            ++cnt[v][u];
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                res = max(res, (int)edges[i].size() + (int)edges[j].size() - cnt[i][j]);
            }
        }
        return res;
    }
};

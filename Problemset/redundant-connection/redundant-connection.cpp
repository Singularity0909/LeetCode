
// @Title: 冗余连接 (Redundant Connection)
// @Author: Singularity0909
// @Date: 2020-09-17 16:42:40
// @Runtime: 8 ms
// @Memory: 8.3 MB

class Solution {
public:
    inline int Find(int x, const vector<int>& pre) {
        return pre[x] == x ? x : Find(pre[x], pre);
    }

    inline void Union(int u, int v, vector<int>& pre) {
        pre[Find(v, pre)] = Find(u, pre);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        vector<int> pre(1001);
        for (int i = 1; i <= 1000; i++) pre[i] = i;
        for (auto& edge : edges) {
            int u = edge.front(), v = edge.back();
            if (Find(u, pre) == Find(v, pre)) {
                res.push_back(u);
                res.push_back(v);
            }
            else Union(u, v, pre);
        }
        return res;
    }
};

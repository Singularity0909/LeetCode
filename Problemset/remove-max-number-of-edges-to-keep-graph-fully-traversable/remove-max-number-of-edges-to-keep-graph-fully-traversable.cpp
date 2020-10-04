
// @Title: 保证图可完全遍历 (Remove Max Number of Edges to Keep Graph Fully Traversable)
// @Author: Singularity0909
// @Date: 2020-09-07 16:57:16
// @Runtime: 1256 ms
// @Memory: 146.6 MB

class Solution {
public:
    using p = pair<int, int>;
    
    vector<int> pre, _pre;

    int Find(int id) {
        return pre[id] == id ? id : pre[id] = Find(pre[id]);
    }

    void Union(int a, int b) {
        pre[Find(b)] = Find(a);
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        pre.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            pre[i] = i;
        }
        vector<p> _edges[3];
        for (auto& edge : edges) {
            _edges[edge[0] - 1].push_back(p(edge[1], edge[2]));
        }
        int cnt = 0;
        for (auto& _edge : _edges[2]) {
            int a = _edge.first, b = _edge.second;
            if (Find(a) != Find(b)) Union(a, b);
            else cnt++;
        }
        _pre = pre;
        for (auto& _edge : _edges[0]) {
            int a = _edge.first, b = _edge.second;
            if (Find(a) != Find(b)) Union(a, b);
            else cnt++;
        }
        for (int i = 1; i <= n; i++) {
            if (Find(i) != Find(1)) {
                return -1;
            }
        }
        pre = _pre;
        for (auto& _edge : _edges[1]) {
            int a = _edge.first, b = _edge.second;
            if (Find(a) != Find(b)) Union(a, b);
            else cnt++;
        }
        for (int i = 1; i <= n; i++) {
            if (Find(i) != Find(1)) {
                return -1;
            }
        }
        return cnt;
    }
};

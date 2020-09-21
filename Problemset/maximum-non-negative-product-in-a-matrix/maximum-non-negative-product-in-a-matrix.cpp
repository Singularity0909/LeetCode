
// @Title: 矩阵的最大非负积 (Maximum Non Negative Product in a Matrix)
// @Author: Singularity0909
// @Date: 2020-09-20 21:48:00
// @Runtime: 28 ms
// @Memory: 10.8 MB

class Solution {
public:
    using ll = long long;
    const int inf = 0x3f3f3f3f;
    const int mod = 1e9 + 7;
    const int dir[2][2] = { 1, 0, 0, 1 };
    size_t n, m;
    vector<vector<bool>> vis;
    vector<vector<ll>> _max, _min;
    
    inline bool inside(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    void dfs(int x, int y, vector<vector<int>>& g) {
        if (vis[x][y]) return;
        vis[x][y] = true;
        if (x == n - 1 && y == m - 1) {
            _max[x][y] = _min[x][y] = g[x][y];
            return;
        }
        for (int i = 0; i < 2; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (!inside(nx, ny)) continue;
            dfs(nx, ny, g);
            if (g[x][y] >= 0) {
                _max[x][y] = max(_max[x][y], _max[nx][ny] * g[x][y]);
                _min[x][y] = min(_min[x][y], _min[nx][ny] * g[x][y]);
            }
            else {
                _max[x][y] = max(_max[x][y], _min[nx][ny] * g[x][y]);
                _min[x][y] = min(_min[x][y], _max[nx][ny] * g[x][y]);
            }
        }
    }
    
    int maxProductPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, vector<bool>(m, false));
        _max.resize(n, vector<ll>(m, -inf));
        _min.resize(n, vector<ll>(m, inf));
        dfs(0, 0, grid);
        return max(_max[0][0] % mod, -1ll);
    }
};

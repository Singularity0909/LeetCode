
// @Title: 二进制矩阵中的最短路径 (Shortest Path in Binary Matrix)
// @Author: Singularity0909
// @Date: 2020-10-14 21:51:26
// @Runtime: 140 ms
// @Memory: 16.4 MB

class Solution {
public:
    using p = pair<int, int>;
    vector<vector<int>>* grid;
    const int dir[8][2] = { 0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1 };
    
    inline int getId(int x, int y, int n)
    {
        return x * n + y;
    }
    
    inline bool legal(int x, int y, int n)
    {
        return x >= 0 and x < n and y >= 0 and y < n and not (*grid)[x][y];
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        if (grid[0][0]) {
            return -1;
        }
        this->grid = &grid;
        queue<p> q;
        q.push(p(0, 1));
        int n = (int)grid.size();
        vector<bool> vis(n * n, false);
        vis[0] = true;
        while (!q.empty()) {
            p cur = q.front();
            q.pop();
            int id = cur.first, dep = cur.second;
            int x = id / n, y = id % n;
            if (x == n - 1 and y == n - 1) {
                return dep;
            }
            for (int i = 0; i < 8; ++i) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                int nid = getId(nx, ny, n);
                if (legal(nx, ny, n) and not vis[nid]) {
                    vis[nid] = true;
                    q.push(p(nid, dep + 1));
                }
            }
        }
        return -1;
    }
};

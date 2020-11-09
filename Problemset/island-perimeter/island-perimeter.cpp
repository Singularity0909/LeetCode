
// @Title: 岛屿的周长 (Island Perimeter)
// @Author: Singularity0909
// @Date: 2020-10-30 10:41:34
// @Runtime: 220 ms
// @Memory: 94.1 MB

class Solution {
public:
    bool inside(int x, int y, int n, int m) {
        return x >= 0 and x < n and y >= 0 and y < m;
    }

    int islandPerimeter(vector<vector<int>>& grid)
    {
        const int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
        using p = pair<int, int>;
        set<p> st;
        size_t n = grid.size(), m = grid[0].size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    sum += 4;
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dir[k][0], y = j + dir[k][1];
                        if (inside(x, y, n, m) and grid[x][y]) {
                            --sum;
                        }
                    }
                }
            }
        }
        return sum;
    }
};

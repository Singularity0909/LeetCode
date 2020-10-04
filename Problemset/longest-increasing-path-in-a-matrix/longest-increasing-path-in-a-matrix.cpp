
// @Title: 矩阵中的最长递增路径 (Longest Increasing Path in a Matrix)
// @Author: Singularity0909
// @Date: 2020-07-26 23:33:10
// @Runtime: 92 ms
// @Memory: 13.7 MB

class Solution {
public:
    const int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
    
    inline bool inside(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& res) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (!inside(nx, ny, (int)matrix.size(), (int)matrix[0].size())) continue;
            if (matrix[nx][ny] <= matrix[x][y]) continue;
            if (res[nx][ny]) res[x][y] = max(res[x][y], res[nx][ny] + 1);
            else res[x][y] = max(res[x][y], dfs(nx, ny, matrix, res) + 1);
        }
        return res[x][y] = max(res[x][y], 1);
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = (int)matrix.size(), m = (int)matrix[0].size(), ans = 0;
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix, res));
            }
        }
        return ans;
    }
};

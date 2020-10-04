
// @Title: 顺时针打印矩阵 (顺时针打印矩阵  LCOF)
// @Author: Singularity0909
// @Date: 2020-07-05 23:37:07
// @Runtime: 20 ms
// @Memory: 10.1 MB

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        size_t n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> vis(n, vector<int>(m, false));
        vector<int> res;
        const int dir[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
        int x = 0, y = 0;
        for (int i = 0, k = 0; i < n * m; i++) {
            res.push_back(matrix[x][y]);
            vis[x][y] = true;
            bool flag = false;
            for (int j = k; j < 4 && !flag; j++) {
                int nx = x + dir[j][0], ny = y + dir[j][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    k = j;
                    x = nx;
                    y = ny;
                    flag = true;
                }
            }
            for (int j = 0; j < k && !flag; j++) {
                int nx = x + dir[j][0], ny = y + dir[j][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    k = j;
                    x = nx;
                    y = ny;
                    flag = true;
                }
            }
        }
        return res;
    }
};

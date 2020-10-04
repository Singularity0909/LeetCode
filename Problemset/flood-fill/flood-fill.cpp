
// @Title: 图像渲染 (Flood Fill)
// @Author: Singularity0909
// @Date: 2020-08-16 09:58:16
// @Runtime: 20 ms
// @Memory: 13.4 MB

class Solution {
public:
    const int dir[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
    
    inline bool inside(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    void dfs(vector<vector<int>>& image, vector<vector<bool>>& vis, int x, int y, int col) {
        vis[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (inside(nx, ny, image.size(), image[0].size()) && !vis[nx][ny] && image[nx][ny] == image[x][y]) {
                dfs(image, vis, nx, ny, col);
            }
        }
        image[x][y] = col;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        size_t n = image.size(), m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dfs(image, vis, sr, sc, newColor);
        return image;
    }
};

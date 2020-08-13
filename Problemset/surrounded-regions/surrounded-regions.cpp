
// @Title: 被围绕的区域 (Surrounded Regions)
// @Author: Singularity0909
// @Date: 2020-08-13 00:22:22
// @Runtime: 36 ms
// @Memory: 10.7 MB

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        size_t n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        using p = pair<int, int>;
        queue<p> q;
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                vis[i][0] = true;
                q.push(p(i, 0));
            }
            if (board[i][m - 1] == 'O') {
                vis[i][m - 1] = true;
                q.push(p(i, m - 1));
            }
        }
        for (int i = 1; i < m - 1; i++) {
            if (board[0][i] == 'O') {
                vis[0][i] = true;
                q.push(p(0, i));
            }
            if (board[n - 1][i] == 'O') {
                vis[n - 1][i] = true;
                q.push(p(n - 1, i));
            }
        }
        const int dir[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
        auto inside = [&](int x, int y) -> bool {
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        while (!q.empty()) {
            p now = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = now.first + dir[i][0];
                int ny = now.second + dir[i][1];
                if (inside(nx, ny) && !vis[nx][ny] && board[nx][ny] == 'O') {
                    vis[nx][ny] = true;
                    q.push(p(nx, ny));
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

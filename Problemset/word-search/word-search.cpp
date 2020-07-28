
// @Title: 单词搜索 (Word Search)
// @Author: Singularity0909
// @Date: 2020-06-13 00:38:01
// @Runtime: 20 ms
// @Memory: 8.2 MB

class Solution {
public:
    int n, m, dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
    bool* vis;
    vector<vector<char>> board;
    string word;

    int getId(int i, int j) {
        return i * m + j;
    }

    bool dfs(int i, int j, int pos) {
        if (board[i][j] != word[pos]) return false;
        if (pos == word.length() - 1) return true;
        vis[getId(i, j)] = true;
        for (int k = 0; k < 4; k++) {
            int x = i + dir[k][0], y = j + dir[k][1];
            if (x < 0 || y < 0 || x >= n || y >= m || vis[getId(x, y)]) continue;
            if (dfs(x, y, pos + 1)) return true;
        }
        vis[getId(i, j)] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        if (!board.size() || !board[0].size()) return false;
        n = (int)board.size();
        m = (int)board[0].size();
        vis = new bool[n * m];
        for (int i = 0; i < n * m; i++) vis[i] = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (dfs(i, j, 0))
                    return true;
        delete[] vis;
        return false;
    }
};

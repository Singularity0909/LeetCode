
// @Title: 解数独 (Sudoku Solver)
// @Author: Singularity0909
// @Date: 2020-11-03 11:11:47
// @Runtime: 36 ms
// @Memory: 7 MB

class Solution {
public:
    using p = pair<int, int>;
    bool flag;
    vector<p> blank;
    vector<vector<bool>> visx, visy, visg;
    
    inline int getGrid(int x, int y) {
        return x / 3 * 3 + y / 3;
    }
    
    void dfs(int id, int val, vector<vector<char>>& board) {
        if (flag) return;
        int x = blank[id].first, y = blank[id].second;
        if (visx[x][val] || visy[y][val] || visg[getGrid(x, y)][val]) return;
        visx[x][val] = visy[y][val] = visg[getGrid(x, y)][val] = true;
        board[x][y] = val + '0';
        if (id == blank.size() - 1) {
            flag = true;
            return;
        }
        for (int i = 1; i <= 9; i++) dfs(id + 1, i, board);
        visx[x][val] = visy[y][val] = visg[getGrid(x, y)][val] = false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        visx.resize(9, vector<bool>(10, false));
        visy.resize(9, vector<bool>(10, false));
        visg.resize(9, vector<bool>(10, false));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    blank.push_back(p(i, j));
                }
                else {
                    int v = board[i][j] - '0';
                    visx[i][v] = true;
                    visy[j][v] = true;
                    visg[getGrid(i, j)][v] = true;
                }
            }
        }
        for (int i = 1; i <= 9; i++) {
            if (!flag) {
                dfs(0, i, board);
            }
        }
    }
};

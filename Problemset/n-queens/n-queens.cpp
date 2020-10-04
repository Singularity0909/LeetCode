
// @Title: N 皇后 (N-Queens)
// @Author: Singularity0909
// @Date: 2020-09-03 11:29:40
// @Runtime: 52 ms
// @Memory: 10.3 MB

class Solution {
public:
    inline vector<string> getBoard(const vector<int>& vec) {
        size_t n = vec.size();
        vector<string> res(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            int p = vec[i];
            res[i][p] = 'Q';
        }
        return res;
    }
    
    inline bool judge(const unordered_set<int>* _set, int x, int y) {
        return _set[0].find(x + y) == _set[0].end() && _set[1].find(x - y) == _set[1].end() && _set[2].find(y) == _set[2].end();
    }
    
    void dfs(int cur, int tot, vector<int> _vec, unordered_set<int> _set[3], vector<vector<string>>& res) {
        if (cur == tot) {
            res.push_back(getBoard(_vec));
            return;
        }
        for (int i = 0; i < tot; i++) {
            int x = cur, y = i;
            if (judge(_set, x, y)) {
                _vec.push_back(i);
                _set[0].insert(x + y);
                _set[1].insert(x - y);
                _set[2].insert(y);
                dfs(cur + 1, tot, _vec, _set, res);
                _vec.pop_back();
                _set[0].erase(x + y);
                _set[1].erase(x - y);
                _set[2].erase(y);
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        dfs(0, n, {}, new unordered_set<int>[3], res);
        return res;
    }
};

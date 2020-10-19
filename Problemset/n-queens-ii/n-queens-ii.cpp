
// @Title: N皇后 II (N-Queens II)
// @Author: Singularity0909
// @Date: 2020-10-17 07:05:33
// @Runtime: 36 ms
// @Memory: 7.9 MB

class Solution {
public:
    inline bool judge(const unordered_set<int>* _set, int x, int y) {
        return _set[0].find(x + y) == _set[0].end() && _set[1].find(x - y) == _set[1].end() && _set[2].find(y) == _set[2].end();
    }
    
    void dfs(int cur, int tot, unordered_set<int> _set[3], int& res) {
        if (cur == tot) {
            res++;
            return;
        }
        for (int i = 0; i < tot; i++) {
            int x = cur, y = i;
            if (judge(_set, x, y)) {
                _set[0].insert(x + y);
                _set[1].insert(x - y);
                _set[2].insert(y);
                dfs(cur + 1, tot, _set, res);
                _set[0].erase(x + y);
                _set[1].erase(x - y);
                _set[2].erase(y);
            }
        }
    }
    
    int totalNQueens(int n) {
        int res = 0;
        dfs(0, n, new unordered_set<int>[3], res);
        return res;
    }
};

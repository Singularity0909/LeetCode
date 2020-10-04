
// @Title: 三角形最小路径和 (Triangle)
// @Author: Singularity0909
// @Date: 2020-07-14 11:14:45
// @Runtime: 8 ms
// @Memory: 8.3 MB

class Solution {
public:
    const int inf = 0x3f3f3f3f;
    int** res;

    int dfs(vector<vector<int>>& t, int i, int j) {
        if (res[i][j] != inf) return res[i][j];
        if (i == t.size() - 1) return res[i][j] = t[i][j];
        return res[i][j] = min(dfs(t, i + 1, j), dfs(t, i + 1, j + 1)) + t[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        size_t n = triangle.size();
        res = (int**)malloc(sizeof(int*) * n);
        for (size_t i = 0; i < n; i++) {
            res[i] = (int*)malloc(sizeof(int) * n);
            for (size_t j = 0; j < n; j++) res[i][j] = inf;
        }
        return dfs(triangle, 0, 0);
    }
};

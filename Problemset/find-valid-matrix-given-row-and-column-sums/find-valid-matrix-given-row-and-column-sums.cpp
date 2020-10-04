
// @Title: 给定行和列的和求可行矩阵 (Find Valid Matrix Given Row and Column Sums)
// @Author: Singularity0909
// @Date: 2020-10-04 22:35:21
// @Runtime: 96 ms
// @Memory: 32.9 MB

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& a, vector<int>& b)
    {
        int n = (int)a.size(), m = (int)b.size();
        vector<vector<int>>ans(n, vector<int>(m, 0));
        int i = 0, j = 0;
        while (j < m and i < n) {
            int v = min(a[i], b[j]);
            ans[i][j] = v;
            a[i] -= v;
            b[j] -= v;
            if (not a[i]) i++;
            if (not b[j]) j++;
        }
        return ans;
    }
};

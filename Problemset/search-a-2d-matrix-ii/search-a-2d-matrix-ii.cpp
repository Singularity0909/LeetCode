
// @Title: 搜索二维矩阵 II (Search a 2D Matrix II)
// @Author: Singularity0909
// @Date: 2020-07-06 01:21:52
// @Runtime: 168 ms
// @Memory: 9.8 MB

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        std::ios::sync_with_stdio(false);
        if (matrix.empty() || matrix[0].empty()) return false;
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = m - 1;
        while (row < n && col >= 0) {
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};

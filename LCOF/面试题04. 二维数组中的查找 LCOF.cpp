// Version 1 bin-search
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        std::ios::sync_with_stdio(false);
        for (vector<int>& vec : matrix) {
            auto it = lower_bound(vec.begin(), vec.end(), target);
            if (it != vec.end() && *it == target)
                return true;
        }
        return false;
    }
};

// Version 2
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        std::ios::sync_with_stdio(false);
        if (matrix.empty() || matrix[0].empty())
            return false;
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = m - 1;
        while (row < n && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            if (matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }
};

// @Title: 二维数组中的查找 (二维数组中的查找 LCOF)
// @Author: Singularity0909
// @Date: 2020-06-24 05:01:34
// @Runtime: 44 ms
// @Memory: 13.4 MB

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

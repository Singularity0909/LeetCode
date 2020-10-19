
// @Title: 有序数组的平方 (Squares of a Sorted Array)
// @Author: Singularity0909
// @Date: 2020-10-16 08:56:55
// @Runtime: 48 ms
// @Memory: 25.4 MB

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A)
    {
        vector<int> res;
        int n = (int)A.size();
        int pos = -1;
        for (int k = 0; k < n; ++k) {
            if (A[k] < 0) {
                pos = k;
            } else {
                break;
            }
        }
        int i = pos, j = pos + 1;
        while (i >= 0 or j < n) {
            if (i < 0) {
                res.push_back(A[j] * A[j]);
                ++j;
            } else if (j >= n) {
                res.push_back(A[i] * A[i]);
                --i;
            } else if (abs(A[i]) <= abs(A[j])) {
                res.push_back(A[i] * A[i]);
                --i;
            } else {
                res.push_back(A[j] * A[j]);
                ++j;
            }
        }
        return res;
    }
};

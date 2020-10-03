
// @Title: 有序矩阵中第K小的元素 (Kth Smallest Element in a Sorted Matrix)
// @Author: Singularity0909
// @Date: 2020-10-01 01:13:54
// @Runtime: 48 ms
// @Memory: 11.7 MB

class Solution {
   public:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int i = n - 1, j = 0;
        int num = 0;
        while (i >= 0 and j < n) {
            if (matrix[i][j] <= mid) {
                num += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return num >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(matrix, mid, k, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

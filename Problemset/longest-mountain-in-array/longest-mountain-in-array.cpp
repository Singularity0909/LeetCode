
// @Title: 数组中的最长山脉 (Longest Mountain in Array)
// @Author: Singularity0909
// @Date: 2020-10-25 21:59:09
// @Runtime: 40 ms
// @Memory: 19.5 MB

class Solution {
public:
    int longestMountain(vector<int>& A)
    {
        int n = (int)A.size();
        vector<int> up(n, 1), down(n, 1);
        for (int i = 1; i < n; ++i) {
            up[i] = A[i] > A[i - 1] ? up[i - 1] + 1 : 1;
            down[i] = A[i] < A[i - 1] ? down[i - 1] + 1 : 1;
        }
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            if (down[i] > 1 and up[i - down[i] + 1] > 1) {
                mx = max(mx, down[i] + up[i - down[i] + 1] - 1);
            }
        }
        return mx;
    }
};


// @Title: 圆圈中最后剩下的数字 (圆圈中最后剩下的数字 LCOF)
// @Author: Singularity0909
// @Date: 2020-08-04 10:15:33
// @Runtime: 8 ms
// @Memory: 8.6 MB

class Solution {
public:
    int lastRemaining(int n, int m) {
        return n == 1 ? 0 : (lastRemaining(n - 1, m) + m) % n;
    }
};

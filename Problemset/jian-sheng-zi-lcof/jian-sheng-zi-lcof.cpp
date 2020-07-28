
// @Title: 剪绳子 (剪绳子  LCOF)
// @Author: Singularity0909
// @Date: 2020-06-13 02:22:42
// @Runtime: 0 ms
// @Memory: 6.2 MB

class Solution {
public:
    int cuttingRope(int n) {
        return n <= 3 ? n - 1 : pow(3, n / 3) * 4 / (4 - n % 3);
    }
};

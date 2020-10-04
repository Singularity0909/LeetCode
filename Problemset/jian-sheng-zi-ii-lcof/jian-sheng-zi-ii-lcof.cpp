
// @Title: 剪绳子 II (剪绳子 II LCOF)
// @Author: Singularity0909
// @Date: 2020-06-13 21:15:40
// @Runtime: 0 ms
// @Memory: 5.7 MB

class Solution {
public:
    const int mod = 1e9 + 7;

    long cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        if (n == 5) return 6;
        if (n == 6) return 9;
        return cuttingRope(n - 3) * 3 % mod;
    }
};

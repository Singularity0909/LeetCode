
// @Title: Pow(x, n) (Pow(x, n))
// @Author: Singularity0909
// @Date: 2020-06-24 05:01:34
// @Runtime: 0 ms
// @Memory: 6 MB

class Solution {
public:
    double myPow(double x, int n) {
        long m = n;
        if (m < 0) {
            m = -m;
            x = 1.0 / x;
        }
        double res = 1.0;
        while (m) {
            if (m & 1) res *= x;
            x *= x;
            m >>= 1;
        }
        return res;
    }
};

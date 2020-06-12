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
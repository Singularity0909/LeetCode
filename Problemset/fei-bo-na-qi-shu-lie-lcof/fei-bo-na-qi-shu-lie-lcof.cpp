
// @Title: 斐波那契数列 (斐波那契数列  LCOF)
// @Author: Singularity0909
// @Date: 2020-06-11 20:57:03
// @Runtime: 0 ms
// @Memory: 5.8 MB

class Solution {
public:
    const int mod = 1e9 + 7;
    int ans[101] = { 0 };

    int fib(int n) {
        if (n < 2)
            return n;
        if (ans[n])
            return ans[n];
        int res = fib(n - 1) + fib(n - 2);
        return ans[n] = (res >= mod ? res % mod : res);
    }
};

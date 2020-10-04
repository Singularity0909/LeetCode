
// @Title: 斐波那契数 (Fibonacci Number)
// @Author: Singularity0909
// @Date: 2020-06-11 20:58:33
// @Runtime: 0 ms
// @Memory: 5.7 MB

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

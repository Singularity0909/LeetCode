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
class Solution {
public:
    const int mod = 1e9 + 7;
    int ans[101] = { 0 };

    int numWays(int n) {
        if (n == 0)
            return 1;
        if (n <= 3)
            return n;
        if (ans[n])
            return ans[n];
        int res = numWays(n - 1) + numWays(n - 2);
        return ans[n] = (res >= mod ? res % mod : res);
    }
};
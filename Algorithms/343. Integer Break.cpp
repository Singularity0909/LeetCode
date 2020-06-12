// Version 1
class Solution {
public:
    int tar, ans[60];
    
    int integerBreak(int n) {
        if (!tar) tar = n;
        if (ans[n]) return ans[n];
        if (n == 1) return 1;
        int res = tar == n ? 0 : n;
        for (int i = 1; i < n; i++)
            res = max(res, integerBreak(i) * integerBreak(n - i));
        return ans[n] = res;
    }
};

// Version 2
class Solution {
public:
    int integerBreak(int n) {
        return n <= 3 ? n - 1 : pow(3, n / 3) * 4 / (4 - n % 3);
    }
};
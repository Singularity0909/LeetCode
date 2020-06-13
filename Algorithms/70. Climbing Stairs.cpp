class Solution {
public:
    int ans[50] = { 0 };

    int climbStairs(int n) {
        if (n <= 3)
            return n;
        return ans[n] ? ans[n] : ans[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};
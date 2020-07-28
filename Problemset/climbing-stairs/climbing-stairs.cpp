
// @Title: 爬楼梯 (Climbing Stairs)
// @Author: Singularity0909
// @Date: 2020-06-11 21:10:10
// @Runtime: 0 ms
// @Memory: 5.7 MB

class Solution {
public:
    int ans[50] = { 0 };

    int climbStairs(int n) {
        if (n <= 3)
            return n;
        return ans[n] ? ans[n] : ans[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};

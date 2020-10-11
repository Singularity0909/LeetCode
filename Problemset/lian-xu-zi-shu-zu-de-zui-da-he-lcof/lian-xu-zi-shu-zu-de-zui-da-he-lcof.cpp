
// @Title: 连续子数组的最大和 (连续子数组的最大和  LCOF)
// @Author: Singularity0909
// @Date: 2020-10-11 20:42:41
// @Runtime: 44 ms
// @Memory: 23.2 MB

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int n = (int)nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

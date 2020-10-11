
// @Title: 最大子序和 (Maximum Subarray)
// @Author: Singularity0909
// @Date: 2020-10-11 20:44:01
// @Runtime: 12 ms
// @Memory: 13.1 MB

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

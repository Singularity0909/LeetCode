
// @Title: 分割等和子集 (Partition Equal Subset Sum)
// @Author: Singularity0909
// @Date: 2020-10-11 01:29:45
// @Runtime: 804 ms
// @Memory: 9 MB

class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        if (not sum) return true;
        sum >>= 1;
        int n = (int)nums.size();
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            for (int j = sum; j >= num; --j) {
                dp[j] = dp[j] | dp[j - num];
            }
        }
        return dp[sum];
    }
};

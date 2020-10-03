
// @Title: 最长上升子序列 (Longest Increasing Subsequence)
// @Author: Singularity0909
// @Date: 2020-10-02 02:07:16
// @Runtime: 4 ms
// @Memory: 7.6 MB

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> up;
        for (int x : nums) {
            auto it = lower_bound(up.begin(), up.end(), x);
            if (it == up.end()) {
                up.push_back(x);
            } else {
                *it = x;
            }
        }
        return (int)up.size();
    }
};

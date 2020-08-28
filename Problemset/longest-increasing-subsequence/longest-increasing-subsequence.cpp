
// @Title: 最长上升子序列 (Longest Increasing Subsequence)
// @Author: Singularity0909
// @Date: 2020-08-28 09:19:50
// @Runtime: 4 ms
// @Memory: 8.1 MB

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vec;
        for (int x : nums) {
            int pos = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
            if (pos == vec.size()) vec.emplace_back(x);
            else vec.at(pos) = x;
        }
        return vec.size();
    }
};

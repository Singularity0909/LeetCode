
// @Title: 只出现一次的数字 (Single Number)
// @Author: Singularity0909
// @Date: 2020-07-05 14:24:15
// @Runtime: 20 ms
// @Memory: 11.5 MB

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int& n : nums) res ^= n;
        return res;
    }
};


// @Title: 数组中数字出现的次数 (数组中数字出现的次数 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-20 02:39:10
// @Runtime: 36 ms
// @Memory: 15.7 MB

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums)
    {
        int res = 0;
        for (int n : nums) res ^= n;
        int a = 0, b = 0, mask = 1;
        while ((mask & res) == 0) mask <<= 1;
        for (int n : nums) {
            if (n & mask) a ^= n;
            else b ^= n;
        }
        return { a, b };
    }
};

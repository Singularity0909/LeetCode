
// @Title: 数组中数字出现的次数 II (数组中数字出现的次数 II LCOF)
// @Author: Singularity0909
// @Date: 2020-07-20 02:48:25
// @Runtime: 80 ms
// @Memory: 16.2 MB

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> cnt(32);
        for(int num : nums) {
            for(int j = 0; j < 32; j++) {
                cnt[j] += num & 1;
                num >>= 1;
            }
        }
        int res = 0;
        for(int i = 0; i < 32; i++) {
            res <<= 1;
            res |= cnt[31 - i] % 3;
        }
        return res;
    }
};

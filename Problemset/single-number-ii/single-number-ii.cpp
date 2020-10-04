
// @Title: 只出现一次的数字 II (Single Number II)
// @Author: Singularity0909
// @Date: 2020-07-05 20:50:37
// @Runtime: 16 ms
// @Memory: 9.2 MB

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (int n : nums) cnt += n >> i & 1;
            res |= cnt % 3 << i;
        }
        return res;
    }
};

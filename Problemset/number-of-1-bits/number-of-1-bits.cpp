
// @Title: 位1的个数 (Number of 1 Bits)
// @Author: Singularity0909
// @Date: 2020-06-24 05:01:34
// @Runtime: 0 ms
// @Memory: 6.1 MB

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};

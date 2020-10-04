
// @Title: 二进制中1的个数 (二进制中1的个数 LCOF)
// @Author: Singularity0909
// @Date: 2020-06-13 02:49:33
// @Runtime: 0 ms
// @Memory: 5.9 MB

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

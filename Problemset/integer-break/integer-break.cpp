
// @Title: 整数拆分 (Integer Break)
// @Author: Singularity0909
// @Date: 2020-06-13 02:22:58
// @Runtime: 0 ms
// @Memory: 6.1 MB

class Solution {
public:
    int integerBreak(int n) {
        return n <= 3 ? n - 1 : pow(3, n / 3) * 4 / (4 - n % 3);
    }
};

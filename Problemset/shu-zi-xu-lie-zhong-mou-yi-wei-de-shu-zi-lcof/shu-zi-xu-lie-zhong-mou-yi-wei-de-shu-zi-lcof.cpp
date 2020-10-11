
// @Title: 数字序列中某一位的数字 (数字序列中某一位的数字  LCOF)
// @Author: Singularity0909
// @Date: 2020-10-11 23:09:54
// @Runtime: 0 ms
// @Memory: 5.7 MB

class Solution {
public:
    int findNthDigit(int n)
    {
        int digit = 1;
        long start = 1, count = 9;
        while (n > count) {
            n -= count;
            ++digit;
            start *= 10;
            count = digit * start * 9;
        }
        long num = start + (n - 1) / digit;
        return to_string(num)[(n - 1) % digit] - '0';
    }
};

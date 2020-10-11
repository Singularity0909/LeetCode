
// @Title: 第N个数字 (Nth Digit)
// @Author: Singularity0909
// @Date: 2020-10-11 23:21:35
// @Runtime: 0 ms
// @Memory: 6 MB

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

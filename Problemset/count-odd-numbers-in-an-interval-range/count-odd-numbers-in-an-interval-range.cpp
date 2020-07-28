
// @Title: 在区间范围内统计奇数数目 (Count Odd Numbers in an Interval Range)
// @Author: Singularity0909
// @Date: 2020-07-25 22:34:09
// @Runtime: 0 ms
// @Memory: 5.9 MB

class Solution {
public:
    int calc(int x) {
        return (x + 1) >> 1;
    }
    
    int countOdds(int low, int high) {
        return calc(high) - calc(low - 1);
    }
};

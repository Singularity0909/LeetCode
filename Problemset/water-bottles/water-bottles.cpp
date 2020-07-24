
// @Title: 换酒问题 (Water Bottles)
// @Author: Singularity0909
// @Date: 2020-07-24 13:08:34
// @Runtime: 0 ms
// @Memory: 6 MB

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int rem = 0;
        int sum = 0;
        while (numBottles) {
            sum += numBottles;
            rem += numBottles;
            numBottles = rem / numExchange;
            rem %= numExchange;
        }
        return sum;
    }
};

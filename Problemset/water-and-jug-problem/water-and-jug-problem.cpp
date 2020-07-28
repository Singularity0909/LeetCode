
// @Title: 水壶问题 (Water and Jug Problem)
// @Author: Singularity0909
// @Date: 2020-04-12 11:44:13
// @Runtime: 0 ms
// @Memory: 5.9 MB

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z > x + y) return false;
        if (z == 0) return true;
        return z % gcd(x, y) == 0;
    }
};

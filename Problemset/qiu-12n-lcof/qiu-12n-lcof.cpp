
// @Title: 求1+2+…+n (求1+2+…+n LCOF)
// @Author: Singularity0909
// @Date: 2020-07-06 13:39:30
// @Runtime: 0 ms
// @Memory: 6.3 MB

class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};


// @Title: 使整数变为 0 的最少操作次数 (Minimum One Bit Operations to Make Integers Zero)
// @Author: Singularity0909
// @Date: 2020-10-05 01:10:06
// @Runtime: 4 ms
// @Memory: 6.1 MB

class Solution {
public:
    int minimumOneBitOperations(int n)
    {
        vector<int> vec;
        while (n) {
            vec.push_back(((n & -n) << 1) - 1);
            n -= n & (-n);
        }
        int sum = 0;
        for (int i = (int)vec.size() - 1, k = 1; i >= 0; --i, k *= -1) {
            sum += k * vec[i];
        }
        return sum;
    }
};

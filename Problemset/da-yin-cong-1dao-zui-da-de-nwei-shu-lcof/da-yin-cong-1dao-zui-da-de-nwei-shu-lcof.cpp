
// @Title: 打印从1到最大的n位数 (打印从1到最大的n位数 LCOF)
// @Author: Singularity0909
// @Date: 2020-06-24 05:01:34
// @Runtime: 16 ms
// @Memory: 11.4 MB

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        for (int i = 1; i < pow(10, n); i++)
            res.push_back(i);
        return res;
    }
};

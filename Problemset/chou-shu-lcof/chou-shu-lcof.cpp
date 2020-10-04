
// @Title: 丑数 (丑数 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-21 22:57:50
// @Runtime: 12 ms
// @Memory: 7.6 MB

class Solution {
public:
    int i2, i3, i5;
    vector<int> res;
    
    int nthUglyNumber(int n)
    {
        res.resize(n);
        res[0] = 1;
        for (int i = 1; i < n; i++) {
            res[i] = (min(min(res[i2] * 2, res[i3] * 3), res[i5] * 5));
            if (res[i] == res[i2] * 2) i2++;
            if (res[i] == res[i3] * 3) i3++;
            if (res[i] == res[i5] * 5) i5++;
        }
        return res[n - 1];
    }
};


// @Title: 根据数字二进制下 1 的数目排序 (Sort Integers by The Number of 1 Bits)
// @Author: Singularity0909
// @Date: 2020-11-06 10:55:04
// @Runtime: 16 ms
// @Memory: 10.2 MB

class Solution {
public:
    int count(int x)
    {
        int cnt = 0;
        while (x) {
            ++cnt;
            x &= x - 1;
        }
        return cnt;
    }

    vector<int> sortByBits(vector<int>& arr)
    {
        auto cmp = [&](int x, int y) {
            int a = count(x), b = count(y);
            if (a not_eq b) return a < b;
            return x < y;
        };
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};

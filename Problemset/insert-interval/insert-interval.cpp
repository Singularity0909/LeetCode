
// @Title: 插入区间 (Insert Interval)
// @Author: Singularity0909
// @Date: 2020-11-04 10:57:51
// @Runtime: 28 ms
// @Memory: 17.2 MB

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> res;
        int a = newInterval.front(), b = newInterval.back();
        int siz = (int)intervals.size();
        int i = 0, j = siz - 1, beg = a, end = b;
        while (i < siz and a > intervals[i].back()) {
            ++i;
        }
        if (i < siz) {
            beg = min(beg, intervals[i].front());
        }
        while (j >= 0 and b < intervals[j].front()) {
            --j;
        }
        if (j >= 0) {
            end = max(end, intervals[j].back());
        }
        for (int k = 0; k < i; ++k) {
            res.push_back(intervals[k]);
        }
        res.push_back({ beg, end });
        for (int k = j + 1; k < siz; ++k) {
            res.push_back(intervals[k]);
        }
        return res;
    }
};

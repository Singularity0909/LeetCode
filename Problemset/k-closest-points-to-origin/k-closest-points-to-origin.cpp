
// @Title: 最接近原点的 K 个点 (K Closest Points to Origin)
// @Author: Singularity0909
// @Date: 2020-11-09 14:12:22
// @Runtime: 648 ms
// @Memory: 38.5 MB

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        auto cmp = [&](const vector<int>& a, const vector<int>& b) {
            return 1ll * a.front() * a.front() + 1ll * a.back() * a.back() < 1ll * b.front() * b.front() + 1ll * b.back() * b.back();
        };
        sort(points.begin(), points.end(), cmp);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

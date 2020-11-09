
// @Title: 两个数组的交集 (Intersection of Two Arrays)
// @Author: Singularity0909
// @Date: 2020-11-02 15:21:00
// @Runtime: 12 ms
// @Memory: 10.3 MB

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(res));
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};

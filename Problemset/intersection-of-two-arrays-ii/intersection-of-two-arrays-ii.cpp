
// @Title: 两个数组的交集 II (Intersection of Two Arrays II)
// @Author: Singularity0909
// @Date: 2020-07-13 00:21:57
// @Runtime: 16 ms
// @Memory: 10.5 MB

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> vec;
        for (int n : nums1) mp[n]++;
        for (int n : nums2) if (mp[n]-- > 0) vec.push_back(n);
        return vec;
    }
};


// @Title: 搜索插入位置 (Search Insert Position)
// @Author: Singularity0909
// @Date: 2020-07-17 01:10:02
// @Runtime: 4 ms
// @Memory: 6.6 MB

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

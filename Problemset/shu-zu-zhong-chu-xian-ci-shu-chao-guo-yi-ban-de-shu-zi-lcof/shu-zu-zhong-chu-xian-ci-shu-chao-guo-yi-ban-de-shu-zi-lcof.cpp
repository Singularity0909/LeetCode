
// @Title: 数组中出现次数超过一半的数字 (数组中出现次数超过一半的数字  LCOF)
// @Author: Singularity0909
// @Date: 2020-07-20 02:50:15
// @Runtime: 88 ms
// @Memory: 18.4 MB

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};


// @Title: 调整数组顺序使奇数位于偶数前面 (调整数组顺序使奇数位于偶数前面 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-04 22:52:51
// @Runtime: 40 ms
// @Memory: 17.7 MB

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            while (left < right && nums[left] & 1) left++;
            while (left < right && !(nums[right] & 1)) right--;
            swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};

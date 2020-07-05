
// @Title: 寻找旋转排序数组中的最小值 (Find Minimum in Rotated Sorted Array)
// @Author: Singularity0909
// @Date: 2020-06-24 05:01:34
// @Runtime: 4 ms
// @Memory: 10 MB

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[right])
                right = mid;
            else
                left = mid + 1;
        }
        return nums[left];
    }
};

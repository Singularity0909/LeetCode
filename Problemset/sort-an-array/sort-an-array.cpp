
// @Title: 排序数组 (Sort an Array)
// @Author: Singularity0909
// @Date: 2020-10-07 09:39:04
// @Runtime: 44 ms
// @Memory: 15.5 MB

class Solution {
public:
    void quickSort(vector<int>& nums, int l, int r)
    {
        if (l >= r) return;
        int i = l, j = r, x = nums[l];
        while (i < j) {
            while (i < j and nums[j] >= x) --j;
            if (i < j) nums[i++] = nums[j];
            while (i < j and nums[i] <= x) ++i;
            if (i < j) nums[j--] = nums[i];
        }
        nums[i] = x;
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
    }

    vector<int> sortArray(vector<int>& nums) 
    {
        quickSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};

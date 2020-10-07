
// @Title: 颜色分类 (Sort Colors)
// @Author: Singularity0909
// @Date: 2020-10-07 09:32:46
// @Runtime: 0 ms
// @Memory: 8.1 MB

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
    
    void sortColors(vector<int>& nums)
    {
        quickSort(nums, 0, nums.size() - 1);
    }
};

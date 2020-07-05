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
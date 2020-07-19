
// @Title: 两数之和 II - 输入有序数组 (Two Sum II - Input array is sorted)
// @Author: Singularity0909
// @Date: 2020-07-20 01:11:15
// @Runtime: 8 ms
// @Memory: 9.4 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = (int)numbers.size() - 1;
        while (i < j) {
            int x = numbers[i], y = numbers[j];
            if (x + y > target) j--;
            else if (x + y < target) i++;
            else return { i + 1, j + 1 };
        }
        return {};
    }
};

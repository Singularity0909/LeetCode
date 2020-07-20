
// @Title: 和为s的两个数字 (和为s的两个数字 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-21 01:28:51
// @Runtime: 460 ms
// @Memory: 100.6 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = (int)numbers.size() - 1;
        while (i < j) {
            int x = numbers[i], y = numbers[j];
            if (x + y > target) j--;
            else if (x + y < target) i++;
            else return { numbers[i], numbers[j] };
        }
        return {};
    }
};

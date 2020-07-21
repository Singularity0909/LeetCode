
// @Title: 旋转数组的最小数字 (旋转数组的最小数字  LCOF)
// @Author: Singularity0909
// @Date: 2020-07-22 00:51:33
// @Runtime: 12 ms
// @Memory: 12 MB

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (numbers[mid] < numbers[right])
                right = mid;
            else if (numbers[mid] > numbers[right])
                left = mid + 1;
            else
                right--;
        }
        return numbers[left];
    }
};

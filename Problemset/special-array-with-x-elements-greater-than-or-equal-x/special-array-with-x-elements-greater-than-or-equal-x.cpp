
// @Title: 特殊数组的特征值 (Special Array With X Elements Greater Than or Equal X)
// @Author: Singularity0909
// @Date: 2020-10-05 00:47:25
// @Runtime: 4 ms
// @Memory: 8.2 MB

class Solution {
public:
    int specialArray(vector<int>& nums)
    {
        int n = (int)nums.size();
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int x : nums) {
                if (x >= i) {
                    cnt++;
                }
            }
            if (cnt == i) {
                return i;
            }
        }
        return -1;
    }
};

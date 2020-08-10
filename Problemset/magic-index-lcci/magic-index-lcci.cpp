
// @Title: 魔术索引 (Magic Index LCCI)
// @Author: Singularity0909
// @Date: 2020-07-31 00:08:30
// @Runtime: 32 ms
// @Memory: 12.8 MB

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == i) {
                return i;
            }
        }
        return -1;
    }
};

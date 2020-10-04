
// @Title: 多数元素 (Majority Element)
// @Author: Singularity0909
// @Date: 2020-07-20 02:52:27
// @Runtime: 24 ms
// @Memory: 8.6 MB

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            if (++mp[x] > nums.size() / 2) {
                return x;
            }
        }
        return -1;
    }
};

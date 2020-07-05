
// @Title: 两数之和 (Two Sum)
// @Author: Singularity0909
// @Date: 2020-07-06 01:25:33
// @Runtime: 0 ms
// @Memory: 8.4 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < (int)nums.size(); i++) {
            int another = target - nums[i];
            if (m.find(another) != m.end()) return { m[another], i };
            m[nums[i]] = i;
        }
        return {};
    }
};


// @Title: 两数之和 (Two Sum)
// @Author: Singularity0909
// @Date: 2020-11-03 11:04:34
// @Runtime: 16 ms
// @Memory: 10 MB

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

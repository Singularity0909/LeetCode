
// @Title: 数组中重复的数字 (数组中重复的数字 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-06 01:24:32
// @Runtime: 80 ms
// @Memory: 22.6 MB

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        bool* vis = new bool[nums.size()];
        for (size_t i = 0; i < nums.size(); i++) vis[i] = false;
        for (int v : nums) {
            if (vis[v]) return v;
            vis[v] = true;
        }
        return -1;
    }
};

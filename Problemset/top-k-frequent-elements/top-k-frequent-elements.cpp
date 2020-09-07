
// @Title: 前 K 个高频元素 (Top K Frequent Elements)
// @Author: Singularity0909
// @Date: 2020-09-07 01:08:02
// @Runtime: 48 ms
// @Memory: 14.2 MB

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp1;
        map<int, vector<int>, greater<int>> mp2;
        vector<int> res;
        for (int x : nums) {
            mp1[x]++;
        }
        for (auto& each : mp1) {
            mp2[each.second].push_back(each.first);
        }
        for (auto& each : mp2) {
            for (int x : each.second) {
                res.push_back(x);
            }
            k -= each.second.size();
            if (!k) break;
        }
        return res;
    }
};

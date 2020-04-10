// Version 1
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<vector<int>, bool> vis;
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        for (int i = 0; i < 1 << n; i++) {
            vector<int> tmp;
            for (int j = i, dig = 0; j; j >>= 1, dig++)
                if (j & 1)
                    tmp.push_back(nums[dig]);
            if (vis.find(tmp) == vis.end()) {
                res.push_back(tmp);
                vis[tmp] = true;
            }
        }
        return res;
    }
};
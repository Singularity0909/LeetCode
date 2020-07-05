
// @Title: 子集 II (Subsets II)
// @Author: Singularity0909
// @Date: 2020-06-24 05:01:34
// @Runtime: 24 ms
// @Memory: 8.1 MB

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        map<vector<int>, bool> vis;
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

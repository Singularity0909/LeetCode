
// @Title: 组合总和 II (Combination Sum II)
// @Author: Singularity0909
// @Date: 2020-09-10 01:35:49
// @Runtime: 84 ms
// @Memory: 24.3 MB

class Solution {
public:
    void dfs(int idx, int tot, int tar, vector<int>& val, vector<int> tmp, set<vector<int>>& res) {
        if (idx >= tot || val[idx] > tar) return;
        tmp.push_back(val[idx]);
        dfs(idx + 1, tot, tar - val[idx], val, tmp, res);
        if (val[idx] == tar) {
            res.insert(tmp);
            return;
        }
        tmp.pop_back();
        dfs(idx + 1, tot, tar, val, tmp, res);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        dfs(0, (int)candidates.size(), target, candidates, {}, res);
        vector<vector<int>> vec;
        for (auto& each : res) vec.push_back(each);
        return vec;
    }
};

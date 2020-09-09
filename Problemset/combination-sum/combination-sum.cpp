
// @Title: 组合总和 (Combination Sum)
// @Author: Singularity0909
// @Date: 2020-09-09 08:13:00
// @Runtime: 56 ms
// @Memory: 27.3 MB

class Solution {
public:
    void dfs(int idx, int tot, int tar, vector<int>& val, vector<int> tmp, vector<vector<int>>& res) {
        if (idx >= tot || val[idx] > tar) return;
        tmp.push_back(val[idx]);
        dfs(idx, tot, tar - val[idx], val, tmp, res);
        if (val[idx] == tar) {
            res.push_back(tmp);
            return;
        }
        tmp.pop_back();
        dfs(idx + 1, tot, tar, val, tmp, res);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        dfs(0, (int)candidates.size(), target, candidates, {}, res);
        return res;
    }
};

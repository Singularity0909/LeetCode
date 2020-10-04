
// @Title: 四数之和 (4Sum)
// @Author: Singularity0909
// @Date: 2020-10-05 01:53:02
// @Runtime: 1068 ms
// @Memory: 14.1 MB

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        using p = pair<int, int>;
        vector<vector<int>> res;
        set<vector<int>> _set;
        multiset<p> _mst;
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            _mst.insert(p(nums[i], i));
        }
        for (int i = 0; i < n - 3; ++i) {
            for (int j = i + 1; j < n - 2; ++j) {
                for (int k = j + 1; k < n - 1; ++k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    auto it = _mst.lower_bound(p(target - sum, k + 1));
                    if (it != _mst.end() and it->first == target - sum) {
                        _set.insert({ nums[i], nums[j], nums[k], target - sum });
                    }
                }
            }
        }
        for (auto& each : _set) {
            vector<int> tmp;
            for (int x : each) {
                tmp.push_back(x);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

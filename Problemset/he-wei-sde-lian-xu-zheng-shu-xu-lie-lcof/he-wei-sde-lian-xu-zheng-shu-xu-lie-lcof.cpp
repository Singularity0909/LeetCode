
// @Title: 和为s的连续正数序列 (和为s的连续正数序列 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-21 02:03:32
// @Runtime: 0 ms
// @Memory: 6.7 MB

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        for (int i = target / 2; i >= 2; i--) {
            double l = 1.0 * target / i - 1.0 * (i - 1) / 2;
            double r = 1.0 * target / i + 1.0 * (i - 1) / 2;
            if (l != (int)l || l < 1) continue;
            vector<int> tmp;
            for (int j = l; j <= r; j++) tmp.push_back(j);
            res.push_back(tmp);
        }
        return res;
    }
};

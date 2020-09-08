
// @Title: 组合 (Combinations)
// @Author: Singularity0909
// @Date: 2020-09-08 01:36:01
// @Runtime: 32 ms
// @Memory: 10.8 MB

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        string str(n - k, '0');
        str += string(k, '1');
        vector<vector<int>> res;
        do {
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                if (str[i] == '1') {
                    tmp.push_back(i + 1);
                }
            }
            res.push_back(tmp);
        } while (next_permutation(str.begin(), str.end()));
        return res;
    }
};

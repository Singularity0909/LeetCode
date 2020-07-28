
// @Title: 判断子序列 (Is Subsequence)
// @Author: Singularity0909
// @Date: 2020-07-27 00:11:10
// @Runtime: 4 ms
// @Memory: 7.1 MB

class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<int> pos[26];
        size_t n = t.length();
        for (int i = 0; i < n; i++) pos[t[i] - 'a'].push_back(i);
        int last = -1;
        for (char c : s) {
            int i = c - 'a';
            int p = int(upper_bound(pos[i].begin(), pos[i].end(), last) - pos[i].begin());
            if (p != pos[i].size()) last = pos[i][p];
            else return false;
        }
        return true;
    }
};

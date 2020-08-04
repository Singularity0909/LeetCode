
// @Title: 字符串的排列 (字符串的排列  LCOF)
// @Author: Singularity0909
// @Date: 2020-08-04 09:09:23
// @Runtime: 44 ms
// @Memory: 17.7 MB

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        sort(s.begin(), s.end());
        do res.emplace_back(s);
        while (next_permutation(s.begin(), s.end()));
        return res;
    }
};

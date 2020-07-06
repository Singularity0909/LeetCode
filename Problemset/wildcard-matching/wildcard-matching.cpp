
// @Title: 通配符匹配 (Wildcard Matching)
// @Author: Singularity0909
// @Date: 2020-07-07 02:10:15
// @Runtime: 68 ms
// @Memory: 27.9 MB

class Solution {
public:
    vector<vector<int>>* vis;
    
    bool isMatch(const string& s, const string& p, size_t i, size_t j) {
        if (~(*vis)[i][j]) return (*vis)[i][j];
        if (j == p.length()) return (*vis)[i][j] = i == s.length();
        if (i == s.length()) return (*vis)[i][j] = j == p.length() || (p[j] == '*' && isMatch(s, p, i, j + 1));
        if (p[j] == '*') return (*vis)[i][j] = isMatch(s, p, i + 1, j) || isMatch(s, p, i + 1, j + 1) || isMatch(s, p, i, j + 1);
        return (*vis)[i][j] = s[i] == p[j] || p[j] == '?' ? isMatch(s, p, i + 1, j + 1) : false;
    }
    
    bool isMatch(string s, string p) {
        vis = new vector<vector<int>>(s.length() + 1, vector<int>(p.length() + 1, -1));
        return isMatch(s, p, 0, 0);
    }
};

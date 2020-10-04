
// @Title: 交错字符串 (Interleaving String)
// @Author: Singularity0909
// @Date: 2020-07-18 01:19:01
// @Runtime: 0 ms
// @Memory: 6.6 MB

class Solution {
public:
    string* s[3];
    vector<vector<bool>>* res;
    
    bool dfs(size_t a, size_t b, size_t c) {
        if ((*res)[a][b]) return false;
        if (c == (*s[2]).length()) return true;
        if (a == (*s[0]).length() + 1 || b == (*s[1]).length() + 1) return !((*res)[a][b] = true);
        if ((*s[2])[c] == (*s[0])[a] && dfs(a + 1, b, c + 1)) return true;
        return !((*res)[a][b] = !((*s[2])[c] == (*s[1])[b] && dfs(a, b + 1, c + 1)));
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        this->s[0] = &s1;
        this->s[1] = &s2;
        this->s[2] = &s3;
        size_t n = s1.length(), m = s2.length();
        res = new vector<vector<bool>>(n + 1, vector<bool>(m + 1, false));
        return dfs(0, 0, 0);
    }
};

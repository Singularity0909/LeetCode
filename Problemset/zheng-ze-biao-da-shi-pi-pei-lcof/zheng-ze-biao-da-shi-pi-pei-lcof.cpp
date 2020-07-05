
// @Title: 正则表达式匹配 (正则表达式匹配 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-04 01:24:09
// @Runtime: 20 ms
// @Memory: 6.1 MB

class Solution {
public:
    bool match(const char* s, const char* p) {
        if (!*p) return !*s;
        if (*(p + 1) != '*') return *s == *p || (*p == '.' && *s) ? match(s + 1, p + 1) : false;
        return *p == *s || (*p == '.' && *s) ? match(s, p + 2) || match(s + 1, p) : match(s, p + 2);
    }
    
    bool isMatch(string s, string p) {
        return match(s.c_str(), p.c_str());
    }
};

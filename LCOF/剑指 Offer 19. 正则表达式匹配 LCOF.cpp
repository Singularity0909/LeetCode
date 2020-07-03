class Solution {
public:
    bool equal(char a, char b) {
        return a == b || (a && b == '.');
    }
    
    bool match(const char* s, const char* p) {
        if (!*p) return !*s;
        if (*(p + 1) != '*') return equal(*s, *p) ? match(s + 1, p + 1) : false;
        return equal(*s, *p) ? match(s, p + 2) || match(s + 1, p) : match(s, p + 2);
    }
    
    bool isMatch(string s, string p) {
        return match(s.c_str(), p.c_str());
    }
};
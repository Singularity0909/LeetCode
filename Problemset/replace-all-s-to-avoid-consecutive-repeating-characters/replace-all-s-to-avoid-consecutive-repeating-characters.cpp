
// @Title: 替换所有的问号 (Replace All ?'s to Avoid Consecutive Repeating Characters)
// @Author: Singularity0909
// @Date: 2020-09-06 17:12:06
// @Runtime: 0 ms
// @Memory: 6 MB

class Solution {
public:
    char getNext(char c) {
        return c = c == 'z' ? 'a' : c + 1;
    }
    
    string modifyString(string s) {
        if (s.size() == 1) {
            return s[0] == '?' ? "a" : s;
        }
        if (s.front() == '?') {
            s.front() = s[1] == '?' ? 'a' : getNext(s[1]);
        }
        for (int i = 1; i < (int)s.length() - 1; i++) {
            if (s[i] != '?') continue;
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != s[i - 1] && c != s[i + 1]) {
                    s[i] = c;
                    break;
                }
            }
        }
        if (s.back() == '?') {
            s.back() = getNext(s[s.length() - 2]);
        }
        return s;
    }
};

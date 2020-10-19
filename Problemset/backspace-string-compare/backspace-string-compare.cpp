
// @Title: 比较含退格的字符串 (Backspace String Compare)
// @Author: Singularity0909
// @Date: 2020-10-19 00:34:23
// @Runtime: 0 ms
// @Memory: 6.2 MB

class Solution {
public:
    string getStr(string s)
    {
        string res;
        for (char c : s) {
            if (c == '#' and not res.empty()) {
                res.pop_back();
            } else if (c not_eq '#') {
                res.push_back(c);
            }
        }
        return res;
    }

    bool backspaceCompare(string a, string b)
    {
        return getStr(a) == getStr(b);
    }
};

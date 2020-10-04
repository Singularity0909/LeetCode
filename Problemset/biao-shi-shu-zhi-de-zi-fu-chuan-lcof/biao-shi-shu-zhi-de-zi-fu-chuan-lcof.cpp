
// @Title: 表示数值的字符串 (表示数值的字符串 LCOF)
// @Author: Singularity0909
// @Date: 2020-09-02 01:14:11
// @Runtime: 4 ms
// @Memory: 5.9 MB

class Solution {
public:
    bool isLeft(string s) {
        if (s.empty() || s == ".") return false;
        if (s.front() == '-' || s.front() == '+') s.erase(0, 1);
        bool flag = false;
        for (char c : s) {
            if (isdigit(c)) continue;
            else if (c == '.' && !flag) flag = true;
            else return false;
        }
        return !s.empty() && s != ".";
    }
    
    bool isRight(string s) {
        if (s.empty()) return false;
        if (s.front() == '-' || s.front() == '+') s.erase(0, 1);
        for (char c : s) if (!isdigit(c)) return false;
        return !s.empty();
    }
    
    bool isNumber(string s) {
        if (s.empty()) return false;
        while (isblank(s.front())) s.erase(0, 1);
        if (s.empty()) return false;
        while (isblank(s.back())) s.pop_back();
        int pos = (int)s.find("e");
        if (pos == string::npos) pos = (int)s.find("E");
        if (pos != string::npos) {
            return isLeft(s.substr(0, pos)) && isRight(s.substr(pos + 1));
        }
        return isLeft(s);
    }
};

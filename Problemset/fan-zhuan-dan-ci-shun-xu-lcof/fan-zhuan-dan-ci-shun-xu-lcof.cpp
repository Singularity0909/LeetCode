
// @Title: 翻转单词顺序 (翻转单词顺序 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-21 02:12:50
// @Runtime: 12 ms
// @Memory: 63 MB

class Solution {
public:
    string reverseWords(string s) {
        while (!s.empty() && isblank(s.back())) s.pop_back();
        stringstream ss(s);
        string tmp, res;
        while (ss >> tmp) res = " " + tmp + res;
        return res.empty() ? res : res.substr(1);
    }
};


// @Title: 左旋转字符串 (左旋转字符串 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-20 03:00:42
// @Runtime: 4 ms
// @Memory: 7.4 MB

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        rotate(s.begin(), s.begin() + (s.length() + n) % s.length(), s.end());
        return s;
    }
};

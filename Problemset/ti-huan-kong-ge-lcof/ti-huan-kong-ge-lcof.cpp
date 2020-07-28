
// @Title: 替换空格 (替换空格 LCOF)
// @Author: Singularity0909
// @Date: 2020-06-10 16:49:27
// @Runtime: 4 ms
// @Memory: 6.5 MB

class Solution {
public:
    string replaceSpace(string s) {
        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                s.erase(i, 1);
                s.insert(i, "%20");
                i += 2;
            }
        }
        return s;
    }
};

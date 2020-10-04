
// @Title: 反转字符串中的单词 III (Reverse Words in a String III)
// @Author: Singularity0909
// @Date: 2020-08-30 14:31:28
// @Runtime: 24 ms
// @Memory: 9.4 MB

class Solution {
public:
    string reverseWords(string s) {
        vector<int> space({ -1 });
        int len = (int)s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                space.push_back(i);
            }
        }
        space.push_back(len);
        for (int i = 0; i < (int)space.size() - 1; i++) {
            int cur = space[i], nxt = space[i + 1];
            reverse(s.begin() + cur + 1, s.begin() + nxt);
        }
        return s;
    }
};

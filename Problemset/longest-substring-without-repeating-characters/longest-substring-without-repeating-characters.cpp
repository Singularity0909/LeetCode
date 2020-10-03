
// @Title: 无重复字符的最长子串 (Longest Substring Without Repeating Characters)
// @Author: Singularity0909
// @Date: 2020-09-30 11:40:03
// @Runtime: 32 ms
// @Memory: 8.4 MB

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> pos;
        int l = 0, r = 0;
        int len = (int)s.length();
        int res = 0;
        while (r < len) {
            char c = s[r];
            if (pos.find(c) != pos.end() and pos[c] >= l) {
                l = pos[c] + 1;
            }
            pos[c] = r++;
            res = max(res, r - l);
        }
        return res;
    }
};

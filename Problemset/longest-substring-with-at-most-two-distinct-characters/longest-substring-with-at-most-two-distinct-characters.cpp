
// @Title: 至多包含两个不同字符的最长子串 (Longest Substring with At Most Two Distinct Characters)
// @Author: Singularity0909
// @Date: 2020-09-30 11:16:58
// @Runtime: 16 ms
// @Memory: 6.6 MB

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        unordered_map<char, int> pos;
        int kind = 0, mx = 0;
        int len = (int)s.length();
        int l = 0, r = 0;
        while (r < len) {
            char c = s[r];
            if (pos.find(c) == pos.end() or pos[c] < l) {
                ++kind;
                while (kind == 3) {
                    if (pos[s[l]] == l) {
                        --kind;
                    }
                    ++l;
                }
            }
            pos[c] = r++;
            mx = max(mx, r - l);
        }
        return mx;
    }
};

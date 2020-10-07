
// @Title: 最长回文子串 (Longest Palindromic Substring)
// @Author: Singularity0909
// @Date: 2020-10-07 01:33:57
// @Runtime: 32 ms
// @Memory: 9.2 MB

class Solution {
public:
    string longestPalindrome(string s)
    {
        int len = (int)s.length();
        int n = len * 2 + 2;
        vector<int> mp(n, 0);
        string ma("$#");
        for (int i = 0; i < len; ++i) {
            ma.push_back(s[i]);
            ma.push_back('#');
        }
        int mx = 0, id = 0, p = 0;
        for (int i = 0; i < n; ++i) {
            mp[i] = mx > i ? min(mx - i, mp[id * 2 - i]) : 1;
            if (i == 0) continue;
            while (ma[i + mp[i]] == ma[i - mp[i]]) {
                ++mp[i];
            }
            if (mx < mp[i] + i) {
                mx = mp[i] + i;
                id = i;
            }
            if (mp[i] > mp[p]) {
                p = i;
            }
        }
        len = mp[p] - 1;
        p = (p - len) / 2;
        return s.substr(p, len);
    }
};

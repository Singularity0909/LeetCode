
// @Title: 第一个只出现一次的字符 (第一个只出现一次的字符  LCOF)
// @Author: Singularity0909
// @Date: 2020-07-20 02:05:10
// @Runtime: 48 ms
// @Memory: 10.6 MB

class Solution {
public:
    char firstUniqChar(string s)
    {
        using p = pair<int, int>;
        vector<p> vis(26);
        size_t n = s.length();
        for (size_t i = 0; i < n; i++) {
            int c = s[i] - 'a';
            vis[c] = p(vis[c].first + 1, vis[c].first ? vis[c].second : i);
        }
        int res = 32, pos = 5e4;
        for (int i = 0; i < 26; i++) {
            if (vis[i].first == 1 && vis[i].second < pos) {
                res = i + 'a';
                pos = vis[i].second;
            }
        }
        return res;
    }
};

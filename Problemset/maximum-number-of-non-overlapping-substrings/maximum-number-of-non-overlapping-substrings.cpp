
// @Title: 最多的不重叠子字符串 (Maximum Number of Non-Overlapping Substrings)
// @Author: Singularity0909
// @Date: 2020-07-24 13:09:00
// @Runtime: 388 ms
// @Memory: 19.9 MB

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<string> res;
        using p = pair<int, int>;
        vector<p> seg(26, p(s.length(), -1));
        for (int i = 0; i < (int)s.length(); i++) {
            int c = s[i] - 'a';
            seg[c].first = min(seg[c].first, i);
            seg[c].second = max(seg[c].second, i);
        }
        for (int i = 0; i < 26; i++) {
            if (seg[i].second == -1) continue;
            for (int j = seg[i].first + 1; j < seg[i].second; j++) {
                int c = s[j] - 'a';
                if (seg[i].first <= seg[c].first && seg[c].second <= seg[i].second) continue;
                seg[i].first = min(seg[i].first, seg[c].first);
                seg[i].second = max(seg[i].second, seg[c].second);
                j = seg[c].first;
            }
        }
        sort(seg.begin(), seg.end(), [](const p& a, const p& b) -> bool { return a.second < b.second; });
        for (int i = 0; i < 26; i++) {
            if (seg[i].second == -1) continue;
            if (i == 0 || seg[i].first > seg[i - 1].second) {
                res.push_back(s.substr(seg[i].first, seg[i].second - seg[i].first + 1));
            }
        }
        return res;
    }
};


// @Title: 划分字母区间 (Partition Labels)
// @Author: Singularity0909
// @Date: 2020-10-22 19:54:03
// @Runtime: 0 ms
// @Memory: 7.1 MB

class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        using p = pair<int, int>;
        vector<p> pos(26);
        for (char c = 'a'; c <= 'z'; ++c) {
            int beg = (int)s.find(c), end = (int)s.find_last_of(c);
            pos[c - 'a'] = p(beg, end);
        }
        vector<p> vec;
        for (int i = 0; i < 26; ++i) {
            if (compl pos[i].first) {
                vec.push_back(pos[i]);
            }
        }
        sort(vec.begin(), vec.end(), [&](const p& a, const p& b) {
            return a.second < b.second;
        });
        deque<p> q;
        for (p& each : vec) {
            int first = each.first;
            while (not q.empty() and each.first < q.back().first) {
                q.pop_back();
            }
            if (not q.empty() and each.first < q.back().second and each.first >= q.back().first) {
                first = q.back().first;
                q.pop_back();
            }
            q.push_back(p(first, each.second));
        }
        vector<int> ans;
        while (not q.empty()) {
            ans.push_back(q.front().second - q.front().first + 1);
            q.pop_front();
        }
        return ans;
    }
};

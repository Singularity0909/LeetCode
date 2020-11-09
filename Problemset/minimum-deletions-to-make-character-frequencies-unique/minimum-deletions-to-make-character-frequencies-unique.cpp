
// @Title: 字符频次唯一的最小删除次数 (Minimum Deletions to Make Character Frequencies Unique)
// @Author: Singularity0909
// @Date: 2020-11-08 11:01:03
// @Runtime: 140 ms
// @Memory: 62.7 MB

class Solution {
public:
    vector<int> vis;
    
    int minDeletions(string s)
    {
        vector<int> cnt(26, 0);
        for (char c : s) {
            ++cnt[c - 'a'];
        }
        vis.resize(100001, 0);
        map<int, int> mp;
        for (int x : cnt) {
            ++vis[x];
        }
        int res = 0;
        for (int i = 1; i <= 100000; ++i) {
            while (vis[i] > 1) {
                int p = i;
                do {
                    ++res;
                    --p;
                } while (p and vis[p]);
                ++vis[p];
                --vis[i];
            }
        }
        return res;
    }
};

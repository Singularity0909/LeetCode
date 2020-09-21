
// @Title: 拆分字符串使唯一子字符串的数目最大 (Split a String Into the Max Number of Unique Substrings)
// @Author: Singularity0909
// @Date: 2020-09-20 20:22:08
// @Runtime: 664 ms
// @Memory: 88.2 MB

class Solution {
public:
    int res;
    string str;
    unordered_map<string, bool> vis;
    
    void dfs(int cur, int lst, int len) {
        if (cur == len) {
            res = max(res, (int)vis.size());
            return;
        }
        if (not vis.count(str.substr(lst + 1, cur - lst))) {
            vis[str.substr(lst + 1, cur - lst)] = true;
            dfs(cur + 1, cur, len);
            vis.erase(str.substr(lst + 1, cur - lst));
        }
        dfs(cur + 1, lst, len);
    }
    
    int maxUniqueSplit(string s) {
        str = s;
        dfs(0, -1, (int)s.length());
        return res;
    }
};

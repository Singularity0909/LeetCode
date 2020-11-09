
// @Title: 单词拆分 (Word Break)
// @Author: Singularity0909
// @Date: 2020-11-01 20:39:40
// @Runtime: 32 ms
// @Memory: 13.7 MB

class Solution {
public:
    string s;
    unordered_set<string> dict;
    vector<bool> ans;
    
    bool dfs(int cur)
    {
        if (not ans[cur]) {
            return false;
        }
        if (dict.find(s.substr(cur)) not_eq dict.end()) {
            return true;
        }
        for (int nxt = cur + 1; nxt < s.length(); ++nxt) {
            if (dict.find(s.substr(cur, nxt - cur)) not_eq dict.end() and dfs(nxt)) {
                return true;
            }
        }
        return ans[cur] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict)
    {
        this->s = s;
        for (const string& each : wordDict) {
            dict.insert(each);
        }
        ans.resize(s.length(), true);
        return dfs(0);
    }
};

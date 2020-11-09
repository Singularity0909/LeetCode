
// @Title: 单词拆分 II (Word Break II)
// @Author: Singularity0909
// @Date: 2020-11-01 20:05:54
// @Runtime: 20 ms
// @Memory: 13.1 MB

class Solution {
private:
    unordered_map<int, vector<string>> ans;
    unordered_set<string> wordSet;

public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        wordSet = unordered_set(wordDict.begin(), wordDict.end());
        backtrack(s, 0);
        return ans[0];
    }

    void backtrack(const string& s, int index)
    {
        if (not ans.count(index)) {
            if (index == s.size()) {
                ans[index] = { "" };
                return;
            }
            ans[index] = {};
            for (int i = index + 1; i <= s.size(); ++i) {
                string word = s.substr(index, i - index);
                if (wordSet.count(word)) {
                    backtrack(s, i);
                    for (const string& succ: ans[i]) {
                        ans[index].push_back(succ.empty() ? word : word + " " + succ);
                    }
                }
            }
        }
    }
};

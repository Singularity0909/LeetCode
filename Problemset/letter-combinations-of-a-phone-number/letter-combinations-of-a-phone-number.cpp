
// @Title: 电话号码的字母组合 (Letter Combinations of a Phone Number)
// @Author: Singularity0909
// @Date: 2020-08-26 00:13:21
// @Runtime: 0 ms
// @Memory: 6.6 MB

class Solution {
public:
    void dfs(int pos, string& str, string now, vector<string>& res, const string s[]) {
        if (pos == str.length()) {
            res.push_back(now);
            return;
        }
        for (char c : s[str[pos] - '0']) {
            now.push_back(c);
            dfs(pos + 1, str, now, res, s);
            now.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        const string s[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> res;
        dfs(0, digits, "", res, s);
        return res;
    }
};

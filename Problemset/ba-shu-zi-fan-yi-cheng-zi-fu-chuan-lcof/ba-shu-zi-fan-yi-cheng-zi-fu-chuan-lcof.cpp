
// @Title: 把数字翻译成字符串 (把数字翻译成字符串 LCOF)
// @Author: Singularity0909
// @Date: 2020-10-11 23:40:14
// @Runtime: 0 ms
// @Memory: 5.8 MB

class Solution {
public:
    int cnt;
    
    void dfs(const string& str, int cur, int last)
    {
        if (cur == str.length()) {
            ++cnt;
            return;
        }
        dfs(str, cur + 1, cur);
        if (cur + 1 != str.length() and str[last + 1] != '0' and stoi(str.substr(last + 1, cur - last + 1)) < 26) {
            dfs(str, cur + 1, last);
        }
    }
    
    int translateNum(int num)
    {
        string str(to_string(num));
        dfs(str, 0, -1);
        return cnt;
    }
};

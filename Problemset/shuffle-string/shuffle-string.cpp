
// @Title: 重新排列字符串 (Shuffle String)
// @Author: Singularity0909
// @Date: 2020-07-26 20:08:33
// @Runtime: 16 ms
// @Memory: 14.8 MB

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        size_t len = s.length();
        string res;
        res.resize(len);
        for (int i = 0; i < len; i++) {
            res[indices[i]] = s[i];
        }
        return res;
    }
};


// @Title: 查找常用字符 (Find Common Characters)
// @Author: Singularity0909
// @Date: 2020-10-14 10:49:15
// @Runtime: 12 ms
// @Memory: 9.5 MB

class Solution {
public:
    vector<string> commonChars(vector<string>& A)
    {
        const int inf(0x3f3f3f3f);
        vector<int> cnt(26, inf);
        for (string& s : A) {
            vector<int> tmp(26, 0);
            for (char& c : s) {
                ++tmp[c - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                cnt[i] = min(cnt[i], tmp[i]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans.push_back(string(1, i + 'a'));
            }
        }
        return ans;
    }
};

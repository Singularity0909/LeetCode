
// @Title: 反转字符串 (Reverse String)
// @Author: Singularity0909
// @Date: 2020-10-08 00:04:21
// @Runtime: 48 ms
// @Memory: 22.6 MB

class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t n = s.size();
        for (int i = 0; i < n / 2; ++i) {
            swap(s[i], s[n - i - 1]);
        }
    }
};

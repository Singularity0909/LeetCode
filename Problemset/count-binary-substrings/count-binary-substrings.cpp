
// @Title: 计数二进制子串 (Count Binary Substrings)
// @Author: Singularity0909
// @Date: 2020-08-10 17:12:25
// @Runtime: 40 ms
// @Memory: 14.3 MB

class Solution {
public:
    int countBinarySubstrings(string s) {
        ios::sync_with_stdio(false);
        size_t n = s.length();
        vector<int> vec(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!i || s[i] != s[i - 1]) vec[i] = 1;
            else vec[i] = vec[i - 1] + 1;
            int j = i - vec[i];
            if (j == -1) continue;
            cnt += vec[j] >= vec[i];
        }
        return cnt;
    }
};

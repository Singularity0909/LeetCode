
// @Title: 字符串的好分割数目 (Number of Good Ways to Split a String)
// @Author: Singularity0909
// @Date: 2020-07-26 00:27:41
// @Runtime: 496 ms
// @Memory: 89.9 MB

class Solution {
public:
    int numSplits(string s) {
        int n = (int)s.length();
        vector<vector<int>> cnt(n + 1, vector<int>(26, 0));
        s = " " + s;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 26; j++) {
                cnt[i][j] = cnt[i - 1][j] + (j == s[i] - 'a');
            }
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int a = 0, b = 0;
            for (int j = 0; j < 26; j++) {
                if (cnt[i][j]) a++;
                if (cnt[n][j] - cnt[i][j]) b++;
            }
            ans += a == b;
        }
        return ans;
    }
};


// @Title: 复原IP地址 (Restore IP Addresses)
// @Author: Singularity0909
// @Date: 2020-08-09 20:30:03
// @Runtime: 20 ms
// @Memory: 8.3 MB

class Solution {
public:
    inline bool check(const string& str, int beg, int end) {
        if (end - beg >= 3) return false;
        int val = stoi(str.substr(beg, end - beg + 1));
        if (str.at(beg) == '0') return end == beg;
        return val >= 0 && val <= 255;
    }
    
    void dfs(const string& str, int now, int last, int cnt, string ans, vector<string>& vec) {
        if (cnt == 5) return;
        if (now == str.length()) {
            if (cnt == 4) {
                vec.push_back(ans);
            }
            return;
        }
        if (now < str.length() - 1) {
            dfs(str, now + 1, last, cnt, ans, vec);
        }
        if (check(str, last + 1, now)) {
            if (!ans.empty()) ans.push_back('.');
            ans += str.substr(last + 1, now - last);
            dfs(str, now + 1, now, cnt + 1, ans, vec);
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        ios::sync_with_stdio(false);
        vector<string> res;
        dfs(s, 0, -1, 0, "", res);
        return res;
    }
};

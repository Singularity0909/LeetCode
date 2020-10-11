
// @Title: 分割两个字符串得到回文串 (Split Two Strings to Make Palindrome)
// @Author: Singularity0909
// @Date: 2020-10-11 19:29:24
// @Runtime: 284 ms
// @Memory: 23.5 MB

class Solution {
public:
    bool judge(const string& a, const string& b)
    {
        int n = (int)a.length();
        for (int i = 0, flag = true; i < n / 2; ++i) {
            int rev = n - i - 1;
            if (a[i] not_eq b[rev]) {
                flag = false;
            }
            if (!flag and a[i] not_eq a[rev]) {
                return false;
            }
        }
        return true;
    }
    
    bool checkPalindromeFormation(string a, string b)
    {
        if (judge(a, b) or judge(b, a)) {
            return true;
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        return judge(a, b) or judge(b, a);
    }
};

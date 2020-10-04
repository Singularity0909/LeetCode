
// @Title: 字符串相加 (Add Strings)
// @Author: Singularity0909
// @Date: 2020-08-03 00:36:07
// @Runtime: 4 ms
// @Memory: 6.6 MB

class Solution {
public:
    string addStrings(string num1, string num2) {
        int len = (int)max(num1.length(), num2.length());
        if (num1.length() < len) num1 = string(len - num1.length(), '0') + num1;
        else num2 = string(len - num2.length(), '0') + num2;
        string res;
        bool flag = false;
        for (int i = len - 1; i >= 0; i--) {
            int val = num1[i] + num2[i] - '0' * 2 + flag;
            res.push_back((val % 10) + '0');
            flag = val / 10;
        }
        if (flag) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};


// @Title: 有效的括号 (Valid Parentheses)
// @Author: Singularity0909
// @Date: 2020-08-14 08:02:51
// @Runtime: 0 ms
// @Memory: 6.4 MB

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char a[128];
        a[')'] = '(';
        a[']'] = '[';
        a['}'] = '{';
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else if (!st.empty() && st.top() == a[s[i]]) {
                st.pop();
            }
            else {
                return false;
            }
        }
        return st.empty();
    }
};

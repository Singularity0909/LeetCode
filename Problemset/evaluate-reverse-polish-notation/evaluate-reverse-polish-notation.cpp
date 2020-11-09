
// @Title: 逆波兰表达式求值 (Evaluate Reverse Polish Notation)
// @Author: Singularity0909
// @Date: 2020-11-08 17:56:26
// @Runtime: 20 ms
// @Memory: 11 MB

class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        unordered_map<string, int> mp({ { "+", 1 }, { "-", 2 }, { "*", 3 }, { "/", 4 } });
        stack<int> st;
        for (const string& s : tokens) {
            int op = mp[s];
            if (not op) {
                st.push(stoi(s));
            } else {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if (op == 1) {
                    st.push(a + b);
                } else if (op == 2) {
                    st.push(a - b);
                } else if (op == 3) {
                    st.push(a * b);
                } else {
                    st.push(a / b);
                }
            }
        }
        return st.top();
    }
};

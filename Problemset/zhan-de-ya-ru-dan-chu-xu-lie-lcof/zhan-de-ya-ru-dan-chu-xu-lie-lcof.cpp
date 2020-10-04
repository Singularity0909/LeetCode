
// @Title: 栈的压入、弹出序列 (栈的压入、弹出序列 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-21 22:04:41
// @Runtime: 16 ms
// @Memory: 14.9 MB

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> st;
        int i = 0;
        for (int x : pushed) {
            st.push(x);
            while (!st.empty() && st.top() == popped[i]) {
                st.pop();
                i++;
            }
        }
        return st.empty();
    }
};

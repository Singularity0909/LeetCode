
// @Title: 验证栈序列 (Validate Stack Sequences)
// @Author: Singularity0909
// @Date: 2020-09-28 19:17:54
// @Runtime: 16 ms
// @Memory: 15.2 MB

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int pos = 0;
        for (int i = 0; i < (int)pushed.size(); ++i) {
            s.push(pushed[i]);
            while (!s.empty() and popped[pos] == s.top()) {
                s.pop();
                ++pos;
            }
        }
        return pos == popped.size();
    }
};

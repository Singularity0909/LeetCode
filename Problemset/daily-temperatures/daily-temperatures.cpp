
// @Title: 每日温度 (Daily Temperatures)
// @Author: Singularity0909
// @Date: 2020-09-28 21:30:32
// @Runtime: 132 ms
// @Memory: 37.6 MB

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size());
        stack<int> st;
        for (int i = T.size() - 1; i >= 0; --i) {
            while (!st.empty() and T[st.top()] <= T[i]) {
                st.pop();
            }
            res[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return res;
    }
};

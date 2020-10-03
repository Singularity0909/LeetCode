
// @Title: 接雨水 (Trapping Rain Water)
// @Author: Singularity0909
// @Date: 2020-09-28 20:42:35
// @Runtime: 0 ms
// @Memory: 7 MB

class Solution {
public:
    int trap(vector<int>& height)
    {
        stack<int> st;
        int sum = 0;
        for (int i = 0; i < (int)height.size(); i++) {
            while (!st.empty() and height[st.top()] < height[i]) {
                int cur = st.top();
                st.pop();
                if (st.empty()) break;
                int l = st.top(), r = i;
                int h = min(height[r], height[l]) - height[cur];
                sum += (r - l - 1) * h;
            }
            st.push(i);
        }
        return sum;
    }
};

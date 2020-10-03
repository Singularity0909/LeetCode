
// @Title: 下一个更大元素 II (Next Greater Element II)
// @Author: Singularity0909
// @Date: 2020-09-28 21:17:14
// @Runtime: 72 ms
// @Memory: 23.6 MB

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        size_t n = nums.size();
        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        vector<int> res(n);
        stack<int> st;
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            while (!st.empty() and st.top() <= nums[i]) {
                st.pop();
            }
            if (i < n) {
                res[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i]);
        }
        return res;
    }
};


// @Title: 下一个更大元素 I (Next Greater Element I)
// @Author: Singularity0909
// @Date: 2020-09-28 21:24:03
// @Runtime: 4 ms
// @Memory: 8.9 MB

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        for (int i = (int)nums2.size() - 1; i >= 0; --i) {
            while (!st.empty() and st.top() <= nums2[i]) {
                st.pop();
            }
            mp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        vector<int> res;
        for (int x : nums1) {
            res.push_back(mp[x]);
        }
        return res;
    }
};

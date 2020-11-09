
// @Title: 独一无二的出现次数 (Unique Number of Occurrences)
// @Author: Singularity0909
// @Date: 2020-10-28 00:04:14
// @Runtime: 4 ms
// @Memory: 8.5 MB

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int, int> mp;
        for (int x : arr) {
            ++mp[x];
        }
        unordered_set<int> st;
        for (auto& each : mp) {
            if (st.find(each.second) == st.end()) {
                st.insert(each.second);
            } else {
                return false;
            }
        }
        return true;
    }
};

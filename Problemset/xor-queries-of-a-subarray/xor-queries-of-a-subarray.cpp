
// @Title: 子数组异或查询 (XOR Queries of a Subarray)
// @Author: Singularity0909
// @Date: 2020-06-13 14:35:43
// @Runtime: 164 ms
// @Memory: 35 MB

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int* sum = new int[arr.size() + 1];
        sum[0] = 0;
        for (size_t i = 1; i <= arr.size(); i++)
            sum[i] = sum[i - 1] ^ arr[i - 1];
        vector<int> ans;
        for (auto each : queries) {
            int l = each[0] + 1, r = each[1] + 1;
            ans.push_back(sum[r] ^ sum[l - 1]);
        }
        return ans;
    }
};

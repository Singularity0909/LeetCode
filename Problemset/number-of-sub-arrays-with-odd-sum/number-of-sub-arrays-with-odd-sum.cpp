
// @Title: 和为奇数的子数组数目 (Number of Sub-arrays With Odd Sum)
// @Author: Singularity0909
// @Date: 2020-07-26 02:07:15
// @Runtime: 376 ms
// @Memory: 105.7 MB

class Solution {
public:
    using ll = long long;
    const int mod = 1e9 + 7;
    
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0, cnt[2] = { 1, 0 };
        ll sum = 0;
        for (int x : arr) {
            sum += x;
            ans = (ans + cnt[!(sum & 1)]) % mod;
            cnt[sum & 1]++;
        }
        return ans;
    }
};

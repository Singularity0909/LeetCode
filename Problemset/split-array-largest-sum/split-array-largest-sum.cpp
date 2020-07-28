
// @Title: 分割数组的最大值 (Split Array Largest Sum)
// @Author: Singularity0909
// @Date: 2020-07-26 01:23:20
// @Runtime: 0 ms
// @Memory: 7 MB

class Solution {
public:
    using ll = long long;
    
    bool check(vector<int>& nums, ll x, int m)
    {
        ll sum = 0;
        int cnt = 1;
        for (int num : nums) {
            if (sum + num > x) {
                cnt++;
                sum = num;
            }
            else sum += num;
        }
        return cnt <= m;
    }
    
    int splitArray(vector<int>& nums, int m)
    {
        ll left = 0, right = 0;
        for (int x : nums) {
            left = max(left, (ll)x);
            right += x;
        }
        while (left < right) {
            ll mid = (left + right) >> 1;
            if (check(nums, mid, m)) right = mid;
            else left = mid + 1;
        }
        return (int)left;
    }
};

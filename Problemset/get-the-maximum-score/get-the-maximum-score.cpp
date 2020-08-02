
// @Title: 最大得分 (Get the Maximum Score)
// @Author: Singularity0909
// @Date: 2020-08-02 16:56:20
// @Runtime: 272 ms
// @Memory: 55.7 MB

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        using ll = long long;
        const int mod = 1e9 + 7;
        size_t n = nums1.size(), m = nums2.size();
        ll sum1 = 0, sum2 = 0, ans = 0;
        size_t i = 0, j = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                sum1 += nums1[i];
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                sum2 += nums2[j];
                j++;
            }
            else {
                ans += max(sum1, sum2) + nums1[i];
                sum1 = sum2 = 0;
                i++;
                j++;
            }
        }
        while (i < n) {
            sum1 += nums1[i];
            i++;
        }
        while (j < m) {
            sum2 += nums2[j];
            j++;
        }
        ans += max(sum1, sum2);
        return ans % mod;
    }
};


// @Title: 形成目标数组的子数组最少增加次数 (Minimum Number of Increments on Subarrays to Form a Target Array)
// @Author: Singularity0909
// @Date: 2020-07-26 00:40:18
// @Runtime: 332 ms
// @Memory: 71.6 MB

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0, last = 0;
        for (int x : target) {
            if (x > last) ans += (x - last);
            last = x;
        }
        return ans;
    }
};


// @Title: 找到最接近目标值的函数值 (Find a Value of a Mysterious Function Closest to Target)
// @Author: Singularity0909
// @Date: 2020-07-27 01:03:49
// @Runtime: 1420 ms
// @Memory: 151.7 MB

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        vector<int> valid({ arr[0] });
        int ans = abs(arr[0] - target);
        for (int& x : arr) {
            vector<int> newValid({ x });
            for (int& pre : valid) {
                newValid.push_back(pre & x);
                ans = min(ans, abs((pre & x) - target));
            }
            ans = min(ans, abs(x - target));
            newValid.erase(unique(newValid.begin(), newValid.end()), newValid.end());
            valid = newValid;
        }
        return ans;
    }
};

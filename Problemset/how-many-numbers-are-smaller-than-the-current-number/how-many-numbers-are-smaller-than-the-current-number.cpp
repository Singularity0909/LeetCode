
// @Title: 有多少小于当前数字的数字 (How Many Numbers Are Smaller Than the Current Number)
// @Author: Singularity0909
// @Date: 2020-10-26 09:47:19
// @Runtime: 16 ms
// @Memory: 10.4 MB

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums)
    {
        vector<int> vec(nums), res;
        sort(vec.begin(), vec.end());
        for (int x : nums) {
            int pos = int(lower_bound(vec.begin(), vec.end(), x) - vec.begin());
            res.push_back(pos);
        }
        return res;
    }
};


// @Title: 只出现一次的数字 III (Single Number III)
// @Author: Singularity0909
// @Date: 2020-07-05 22:22:36
// @Runtime: 20 ms
// @Memory: 10.1 MB

// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         for (int n : nums)
//             if (++mp[n] == 2)
//                 mp.erase(n);
//         vector<int> res;
//         for (auto p : mp) res.push_back(p.first);
//         return res;
//     }
// };

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (int n : nums) x ^= n;
        x &= -x;
        vector<int> res(2, 0);
        for (int n : nums) res[n & x ? 1 : 0] ^= n;
        return res;
    }
};

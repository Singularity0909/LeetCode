
// @Title: 只出现一次的数字 III (Single Number III)
// @Author: Singularity0909
// @Date: 2020-07-06 01:15:20
// @Runtime: 16 ms
// @Memory: 10 MB

// Version 1 bit
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

// Version 2 hash
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

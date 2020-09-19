
// @Title: 全排列 II (Permutations II)
// @Author: Singularity0909
// @Date: 2020-09-18 00:14:24
// @Runtime: 4 ms
// @Memory: 7.6 MB

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do res.push_back(nums);
        while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
};

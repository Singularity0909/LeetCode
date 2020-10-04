
// @Title: 跳水板 (Diving Board LCCI)
// @Author: Singularity0909
// @Date: 2020-07-08 00:21:30
// @Runtime: 28 ms
// @Memory: 19.8 MB

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if (!k) return {};
        if (shorter == longer) return { shorter * k };
        vector<int> ans;
        for (int i = 0; i <= k; i++)
            ans.push_back(shorter * (k - i) + longer * i);
        return ans;
    }
};

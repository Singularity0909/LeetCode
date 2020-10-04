
// @Title: 扑克牌中的顺子 (扑克牌中的顺子  LCOF)
// @Author: Singularity0909
// @Date: 2020-08-04 11:39:47
// @Runtime: 0 ms
// @Memory: 10.1 MB

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> vec;
        int cnt = 0;
        for (int x : nums) {
            if (x == 0) cnt++;
            else vec.push_back(x);
        }
        if (vec.empty()) return true;
        int last = vec.front();
        for (int i = 1; i < (int)vec.size(); i++) {
            if (vec[i] == last) return false;
            cnt -= vec[i] - last - 1;
            last = vec[i];
        }
        return cnt >= 0;
    }
};

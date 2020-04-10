class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = (int)nums.size();
        for (int i = 0; i < 1 << n; i++) {
            vector<int> tmp;
            for (int j = i, dig = 0; j; j >>= 1, dig++)
                if (j & 1)
                    tmp.push_back(nums[dig]);
            res.push_back(tmp);
        }
        return res;
    }
};
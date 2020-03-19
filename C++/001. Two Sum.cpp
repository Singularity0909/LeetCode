// Version 1 bin-search
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        using p = pair<int, int>;
        vector<p> pairs;
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); i++) pairs.push_back(p(nums[i], i));
        sort(pairs.begin(), pairs.end());
        for (auto it = pairs.begin(); it != pairs.end(); it++) {
            int a = it->first;
            int b = target - a;
            auto _it = lower_bound(it + 1, pairs.end(), p(b, 0));
            if (_it != pairs.end() && it->first + _it->first == target) {
                res.push_back(it->second);
                res.push_back(_it->second);
                break;
            }
        }
        return res;
    }
};

// Version 2 hash
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < (int)nums.size(); i++) {
            int another = target - nums[i];
            if (m.find(another) != m.end())
                return { m[another], i };
            m[nums[i]] = i;
        }
        return {};
    }
};
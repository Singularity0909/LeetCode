
// @Title: 最小区间 (Smallest Range Covering Elements from K Lists)
// @Author: Singularity0909
// @Date: 2020-08-01 21:35:50
// @Runtime: 168 ms
// @Memory: 12.4 MB

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums)
    {
        int rangeLeft = 0, rangeRight = INT_MAX;
        size_t size = nums.size();
        vector<int> nxt(size);
        auto cmp = [&](const int& u, const int& v) {
            return nums[u][nxt[u]] > nums[v][nxt[v]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int minValue = 0, maxValue = INT_MIN;
        for (int i = 0; i < size; ++i) {
            pq.emplace(i);
            maxValue = max(maxValue, nums[i][0]);
        }
        while (true) {
            int row = pq.top();
            pq.pop();
            minValue = nums[row][nxt[row]];
            if (maxValue - minValue < rangeRight - rangeLeft) {
                rangeLeft = minValue;
                rangeRight = maxValue;
            }
            if (nxt[row] == nums[row].size() - 1) break;
            ++nxt[row];
            maxValue = max(maxValue, nums[row][nxt[row]]);
            pq.emplace(row);
        }
        return { rangeLeft, rangeRight };
    }
};

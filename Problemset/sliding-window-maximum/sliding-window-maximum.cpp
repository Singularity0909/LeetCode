
// @Title: 滑动窗口最大值 (Sliding Window Maximum)
// @Author: Singularity0909
// @Date: 2020-07-21 18:34:56
// @Runtime: 96 ms
// @Memory: 28.5 MB

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        vector<int> vec;
        deque<int> dq;
        for (int i = 0; i < (int)nums.size(); i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            while (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
            dq.push_back(i);
            if (i >= k - 1) vec.emplace_back(nums[dq.front()]);
        }
        return vec;
    }
};

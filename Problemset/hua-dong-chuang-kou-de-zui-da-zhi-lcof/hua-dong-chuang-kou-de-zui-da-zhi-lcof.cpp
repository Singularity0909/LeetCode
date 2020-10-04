
// @Title: 滑动窗口的最大值 (滑动窗口的最大值 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-21 18:25:33
// @Runtime: 44 ms
// @Memory: 15.9 MB

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vec;
        deque<int> dq;
        for (int i = 0; i < (int)nums.size(); i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            while (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
            dq.push_back(i);
            if (i >= k - 1) vec.push_back(nums[dq.front()]);
        }
        return vec;
    }
};

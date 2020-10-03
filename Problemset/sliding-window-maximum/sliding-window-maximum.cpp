
// @Title: 滑动窗口最大值 (Sliding Window Maximum)
// @Author: Singularity0909
// @Date: 2020-10-02 17:02:30
// @Runtime: 504 ms
// @Memory: 104.2 MB

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (!q.empty() and i - q.front() == k) {
                q.pop_front();
            }
            while (!q.empty() and nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.emplace_back(i);
            if (i >= k - 1) {
                res.emplace_back(nums[q.front()]);
            }
        }
        return res;
    }
};

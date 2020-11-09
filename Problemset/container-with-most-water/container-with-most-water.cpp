
// @Title: 盛最多水的容器 (Container With Most Water)
// @Author: Singularity0909
// @Date: 2020-11-03 11:11:41
// @Runtime: 36 ms
// @Memory: 17.7 MB

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int mx = 0;
        int l = 0, r = (int)height.size() - 1;
        while (l < r) {
            mx = max(mx, min(height[r], height[l]) * (r - l));
            if (height[l] >= height[r]) {
                r--;
            } else {
                l++;
            }
        }
        return mx;
    }
};

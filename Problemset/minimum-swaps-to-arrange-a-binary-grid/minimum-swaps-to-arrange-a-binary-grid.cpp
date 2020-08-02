
// @Title: 排布二进制网格的最少交换次数 (Minimum Swaps to Arrange a Binary Grid)
// @Author: Singularity0909
// @Date: 2020-08-03 01:18:17
// @Runtime: 180 ms
// @Memory: 26 MB

class Solution {
public:
    int getNum(const vector<int>& vec) {
        int cnt = 0;
        for (auto it = vec.rbegin(); it != vec.rend(); it++) {
            if (!*it) cnt++;
            else break;
        }
        return cnt;
    }
    
    int minSwaps(vector<vector<int>>& grid) {
        int cnt = 0;
        size_t n = grid.size();
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = getNum(grid[i]);
        for (int i = 0; i < n; i++) {
            if (nums[i] >= n - i - 1) continue;
            bool found = false;
            for (int j = i + 1; j < n && !found; j++) {
                if (nums[j] < n - i - 1) continue;
                found = true;
                for (int k = j; k > i; k--) {
                    swap(nums[k], nums[k - 1]);
                    cnt++;
                }
            }
            if (!found) return -1;
        }
        return cnt;
    }
};

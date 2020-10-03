
// @Title: 最多可达成的换楼请求数目 (Maximum Number of Achievable Transfer Requests)
// @Author: Singularity0909
// @Date: 2020-09-27 12:12:06
// @Runtime: 324 ms
// @Memory: 8.8 MB

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = (int)requests.size(), ans = 0;
        for (int i = 0; i < (1 << m); i++) {
            int num[40] = { 0 };
            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    num[requests[j][0]]--;
                    num[requests[j][1]]++;
                }
            }
            bool flag = false;
            for (int i = 0; i < n; i++) {
                if (num[i]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                ans = max(ans, __builtin_popcount(i));
            }
        }
        return ans;
    }
};

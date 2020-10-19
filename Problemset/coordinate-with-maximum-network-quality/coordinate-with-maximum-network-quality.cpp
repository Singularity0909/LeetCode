
// @Title: 网络信号最好的坐标 (Coordinate With Maximum Network Quality)
// @Author: Singularity0909
// @Date: 2020-10-17 23:07:02
// @Runtime: 1420 ms
// @Memory: 8.9 MB

class Solution {
public:
    using p = pair<int, int>;
    
    inline double getDis(const p& a, const p& b)
    {
        return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
    }
    
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius)
    {
        int n = (int)towers.size();
        int mx = -1;
        p ans;
        for (int x = -50; x <= 100; ++x) {
            for (int y = -50; y <= 100; ++y) {
                int sum = 0;
                for (int i = 0; i < n; ++i) {
                    int xx = towers[i][0], yy = towers[i][1];
                    double dis = getDis(p(xx, yy), p(x, y));
                    if (dis <= radius) {
                        sum += 1.0 * towers[i][2] / (1.0 + dis);
                    }
                }
                if (sum > mx) {
                    mx = sum;
                    ans = p(x, y);
                } else if (sum == mx) {
                    ans = min(ans, p(x, y));
                }
            }
        }
        return { ans.first, ans.second };
    }
};

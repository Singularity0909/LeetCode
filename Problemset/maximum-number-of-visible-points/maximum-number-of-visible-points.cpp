
// @Title: 可见点的最大数目 (Maximum Number of Visible Points)
// @Author: Singularity0909
// @Date: 2020-10-05 01:07:52
// @Runtime: 1228 ms
// @Memory: 120.1 MB

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location)
    {
        const double pi = acos(-1);
        using p = pair<int, int>;
        double ag = pi * angle / 180;
        vector<double> phi, phi2;
        int cnt = 0;
        for (auto& each : points) {
            int dx = each.front() - location.front();
            int dy = each.back() - location.back();
            double _ag1 = atan2(1.0 * dy, 1.0 * dx);
            if (dx == 0 and dy == 0) {
                cnt++;
            } else {
                phi.push_back(_ag1);
            }
        }
        sort(phi.begin(), phi.end());
        int mx = 0;
        for (int i = 0; i < (int)phi.size(); ++i) {
            double cur = phi[i];
            auto it = upper_bound(phi.begin(), phi.end(), cur + ag);
            int pos = int(it - phi.begin() - 1);
            int now = pos - i + 1;
            double x = cur + ag;
            if (x > pi) {
                double t = -pi * 2 + x;
                now += int(upper_bound(phi.begin(),phi.end(),t) - phi.begin());
            }
            mx = max(mx, now);
        }
        return mx + cnt;
    }
};

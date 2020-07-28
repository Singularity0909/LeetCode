
// @Title: 灯泡开关 IV (Bulb Switcher IV)
// @Author: Singularity0909
// @Date: 2020-07-26 20:11:47
// @Runtime: 44 ms
// @Memory: 10.5 MB

class Solution {
public:
    int minFlips(string target) {
        size_t len = target.length();
        target.insert(0, "0");
        int cnt = 0;
        for (int i = len; i >= 1; i--) {
            if (target[i] != target[i - 1]) {
                cnt++;
            }
        }
        return cnt;
    }
};

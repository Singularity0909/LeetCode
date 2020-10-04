
// @Title: 机器人能否返回原点 (Robot Return to Origin)
// @Author: Singularity0909
// @Date: 2020-08-28 08:07:33
// @Runtime: 16 ms
// @Memory: 7.8 MB

class Solution {
public:
    bool judgeCircle(string moves) {
        int cnt_u = 0, cnt_d = 0, cnt_l = 0, cnt_r = 0;
        for (char c : moves) {
            if (c == 'U') cnt_u++;
            else if (c == 'D') cnt_d++;
            else if (c == 'L') cnt_l++;
            else cnt_r++;
        }
        return cnt_u == cnt_d && cnt_l == cnt_r;
    }
};

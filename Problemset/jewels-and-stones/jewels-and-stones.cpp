
// @Title: 宝石与石头 (Jewels and Stones)
// @Author: Singularity0909
// @Date: 2020-10-02 02:06:27
// @Runtime: 0 ms
// @Memory: 5.9 MB

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<bool> gem(128, false);
        for (char c : J) {
            gem[c] = true;
        }
        int cnt = 0;
        for (char c : S) {
            if (gem[c]) {
                cnt++;
            }
        }
        return cnt;
    }
};


// @Title: 找出数组游戏的赢家 (Find the Winner of an Array Game)
// @Author: Singularity0909
// @Date: 2020-08-02 13:11:12
// @Runtime: 292 ms
// @Memory: 66.9 MB

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int mx = 0;
        deque<int> dq;
        for (int x : arr) {
            mx = max(mx, x);
            dq.push_back(x);
        }
        int cnt = 0;
        int first = dq.front();
        dq.pop_front();
        while (true) {
            int second = dq.front();
            dq.pop_front();
            if (first > second) {
                cnt++;
                dq.push_back(second);
            }
            else {
                cnt = 1;
                dq.push_back(first);
                first = second;
            }
            if (cnt == k || first == mx) return first;
        }
        return -1;
    }
};

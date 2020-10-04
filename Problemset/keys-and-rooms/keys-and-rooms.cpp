
// @Title: 钥匙和房间 (Keys and Rooms)
// @Author: Singularity0909
// @Date: 2020-08-31 15:19:44
// @Runtime: 16 ms
// @Memory: 9.6 MB

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        size_t n = rooms.size();
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int cnt = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            cnt++;
            for (int nxt : rooms[cur]) {
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        return cnt == n;
    }
};

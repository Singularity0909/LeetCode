
// @Title: 机器人的运动范围 (机器人的运动范围  LCOF)
// @Author: Singularity0909
// @Date: 2020-06-13 02:00:53
// @Runtime: 0 ms
// @Memory: 7 MB

class Solution {
public:
    const int maxn = 1e2;
    const int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
    int m, n, k;
    bool** vis;
    
    int getVal(int i, int j) {
        int res = 0;
        while (i) {
            res += i % 10;
            i /= 10;
        }
        while (j) {
            res += j % 10;
            j /= 10;
        }
        return res;
    }
    
    bool inside(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    
    int dfs(int i, int j) {
        vis[i][j] = true;
        int cnt = 1;
        for (int d = 0; d < 4; d++) {
            int x = i + dir[d][0], y = j + dir[d][1];
            if (inside(x, y) && !vis[x][y] && getVal(x, y) <= k) cnt += dfs(x, y);
        }
        return cnt;
    }
    
    int movingCount(int m, int n, int k) {
        this->m = m;
        this->n = n;
        this->k = k;
        vis = new bool*[maxn];
        for (int i = 0; i < maxn; i++) {
            vis[i] = new bool[maxn];
            for (int j = 0; j < maxn; j++) vis[i][j] = false;
        }
        return dfs(0, 0);
    }
};

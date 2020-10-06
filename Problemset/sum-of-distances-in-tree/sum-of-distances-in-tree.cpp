
// @Title: 树中距离之和 (Sum of Distances in Tree)
// @Author: Singularity0909
// @Date: 2020-10-06 08:53:59
// @Runtime: 152 ms
// @Memory: 26.5 MB

class Solution {
public:
    vector<int> siz;
    vector<int> dis;
    vector<int> res;
    vector<vector<int>> son;
    
    void dfs(int cur, int pre)
    {
        siz[cur] = 1;
        if (cur != pre) {
            dis[cur] = dis[pre] + 1;
        }
        int dis_sum = 0;
        for (int nxt : son[cur]) {
            if (nxt != pre) {
                dfs(nxt, cur);
                siz[cur] += siz[nxt];
                dis_sum += dis[nxt];
            }
        }
        dis[cur] += dis_sum;
    }
    
    void dfs(int cur, int pre, int tot)
    {
        if (cur == pre) {
            res[cur] = dis[cur];
        } else {
            res[cur] = res[pre] - siz[cur] * 2 + tot;
        }
        for (int nxt : son[cur]) {
            if (nxt != pre) {
                dfs(nxt, cur, tot);
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
    {
        siz.resize(n, 0);
        dis.resize(n, 0);
        son.resize(n);
        res.resize(n);
        for (auto& each : edges) {
            son[each.front()].push_back(each.back());
            son[each.back()].push_back(each.front());
        }
        dfs(0, 0);
        dfs(0, 0, n);
        return res;
    }
};

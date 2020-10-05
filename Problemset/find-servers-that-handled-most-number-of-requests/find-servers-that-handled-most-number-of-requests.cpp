
// @Title: 找到处理最多请求的服务器 (Find Servers That Handled Most Number of Requests)
// @Author: Singularity0909
// @Date: 2020-10-05 11:52:03
// @Runtime: 552 ms
// @Memory: 90.6 MB

class Solution {
public:
    static const int maxn = 1e5 + 10;
    
    struct node {
        int l, r, v;
    } tree[maxn << 2];
    
    inline int ls(int cur)
    {
        return cur << 1;
    }
    
    inline int rs(int cur)
    {
        return cur << 1 | 1;
    }
    
    void push_up(int cur)
    {
        tree[cur].v = min(tree[ls(cur)].v, tree[rs(cur)].v);
    }
    
    void build(int cur, int l, int r)
    {
        tree[cur].l = l;
        tree[cur].r = r;
        if (l == r) {
            tree[cur].v = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(cur), l, mid);
        build(rs(cur), mid + 1, r);
        push_up(cur);
    }
    
    void update(int cur, int pos, int val)
    {
        if (tree[cur].l == pos and tree[cur].r == pos) {
            tree[cur].v = val;
            return;
        }
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (pos <= mid) {
            update(ls(cur), pos, val);
        } else {
            update(rs(cur), pos, val);
        }
        push_up(cur);
    }
    
    int query(int cur, int l, int r, int val)
    {
        if (l > r) {
            return 0;
        }
        if (tree[cur].l == tree[cur].r) {
            return tree[cur].v <= val ? tree[cur].l : 0;
        }
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (r <= mid) {
            return query(ls(cur), l, r, val);
        }
        if (l > mid) {
            return query(rs(cur), l, r, val);
        }
        int res = 0;
        if (tree[ls(cur)].v <= val) {
            res = query(ls(cur), l, mid, val);
        }
        if (not res and tree[rs(cur)].v <= val) {
            res = query(rs(cur), mid + 1, r, val);
        }
        return res;
    }
    
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load)
    {
        int n = (int)arrival.size();
        vector<int> vis(k, 0);
        build(1, 1, k);
        for (int i = 0; i < n; ++i) {
            int val = arrival[i];
            int pos = query(1, i % k + 1, k, val);
            if (not pos) {
                pos = query(1, 1, i % k, val);
            }
            if (pos) {
                update(1, pos, val + load[i]);
                ++vis[pos - 1];
            }
        }
        int mx = 0;
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            if (vis[i] == mx) {
                ans.push_back(i);
            } else if (vis[i] > mx) {
                mx = vis[i];
                ans.clear();
                ans.push_back(i);
            }
        }
        return ans;
    }
};

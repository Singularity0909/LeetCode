
// @Title: 区间和的个数 (Count of Range Sum)
// @Author: Singularity0909
// @Date: 2020-11-07 22:55:13
// @Runtime: 136 ms
// @Memory: 20.1 MB

class SegmentTree {
private:
    struct node {
        int l, r, v;
    } tree[400000];
    
public:
    inline int ls(int cur)
    {
        return cur << 1;
    }
    
    inline int rs(int cur)
    {
        return cur << 1 | 1;
    }
    
    void build(int cur, int l, int r)
    {
        tree[cur].l = l;
        tree[cur].r = r;
        tree[cur].v = 0;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(ls(cur), l, mid);
        build(rs(cur), mid + 1, r);
    }
    
    void insert(int cur, int pos)
    {
        ++tree[cur].v;
        if (tree[cur].l == pos and tree[cur].r == pos) return;
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (pos <= mid) {
            insert(ls(cur), pos);
        } else {
            insert(rs(cur), pos);
        }
    }
    
    int query(int cur, int l, int r)
    {
        if (tree[cur].l == l and tree[cur].r == r) {
            return tree[cur].v;
        }
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (r <= mid) {
            return query(ls(cur), l, r);
        }
        if (l > mid) {
            return query(rs(cur), l, r);
        }
        return query(ls(cur), l, mid) + query(rs(cur), mid + 1, r);
    }
};

class Solution {
public:
    using ll = long long;
    SegmentTree tree;
    vector<ll> vals;
    
    inline int getId(ll val)
    {
        return int(lower_bound(vals.begin(), vals.end(), val) - vals.begin()) + 1;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper)
    {
        int siz = (int)nums.size();
        vector<ll> pre(siz + 1, 0);
        for (int i = 1; i <= siz; ++i) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        for (ll x : pre) {
            vals.push_back(x);
            vals.push_back(x - upper);
            vals.push_back(x - lower);
        }
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        tree.build(1, 1, (int)vals.size());
        int res = 0;
        for (ll x : pre) {
            ll l = x - upper, r = x - lower;
            res += tree.query(1, getId(l), getId(r));
            tree.insert(1, getId(x));
        }
        return res;
    }
};

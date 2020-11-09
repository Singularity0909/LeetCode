
// @Title: 奇妙序列 (Fancy Sequence)
// @Author: Singularity0909
// @Date: 2020-11-03 11:21:24
// @Runtime: 1508 ms
// @Memory: 317.6 MB

class Fancy {
public:
    using ll = long long;
    
    static const int maxn = 1e5 + 1;
    static const int mod = 1e9 + 7;
    int tot;
    
    struct node {
        int l, r;
        ll sum, mult, add;
        node() { l = r = sum = add = 0; mult = 1; }
    } tree[maxn << 2];
    
    inline int ls(int id)
    {
        return id << 1;
    }
    
    inline int rs(int id)
    {
        return id << 1 | 1;
    }
    
    void push_up(int id)
    {
        tree[id].sum = (tree[ls(id)].sum + tree[rs(id)].sum) % mod;
    }

    void push_down(int id)
    {
        if (tree[id].add or tree[id].mult != 1) {
            tree[ls(id)].sum = (tree[ls(id)].sum * tree[id].mult + (tree[ls(id)].r - tree[ls(id)].l + 1) * tree[id].add) % mod;
            tree[rs(id)].sum = (tree[rs(id)].sum * tree[id].mult + (tree[rs(id)].r - tree[rs(id)].l + 1) * tree[id].add) % mod;
            tree[ls(id)].mult = tree[ls(id)].mult * tree[id].mult % mod;
            tree[rs(id)].mult = tree[rs(id)].mult * tree[id].mult % mod;
            tree[ls(id)].add = (tree[ls(id)].add * tree[id].mult + tree[id].add) % mod;
            tree[rs(id)].add = (tree[rs(id)].add * tree[id].mult + tree[id].add) % mod;
            tree[id].mult = 1;
            tree[id].add = 0;
        }
    }
    
    void build(int id, int l, int r)
    {
        if ((tree[id].l = l) == (tree[id].r = r)) {
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(id), l, mid);
        build(rs(id), mid + 1, r);
        push_up(id);
    }
    
    void mult(int id, int l, int r, ll x)
    {
        if (tree[id].l == l and tree[id].r == r) {
            tree[id].sum = tree[id].sum * x % mod;
            tree[id].mult = tree[id].mult * x % mod;
            tree[id].add = tree[id].add * x % mod;
            return;
        }
        push_down(id);
        int mid = (tree[id].l + tree[id].r) >> 1;
        if (r <= mid) {
            mult(ls(id), l, r, x);
        } else if (l > mid) {
            mult(rs(id), l, r, x);
        } else {
            mult(ls(id), l, mid, x);
            mult(rs(id), mid + 1, r, x);
        }
        push_up(id);
    }

    void add(int id, int l, int r, ll x)
    {
        if (tree[id].l == l and tree[id].r == r) {
            tree[id].sum = (tree[id].sum + (r - l + 1) * x) % mod;
            tree[id].add = (tree[id].add + x) % mod;
            return;
        }
        push_down(id);
        int mid = (tree[id].l + tree[id].r) >> 1;
        if (r <= mid) {
            add(ls(id), l, r, x);
        } else if (l > mid) {
            add(rs(id), l, r, x);
        } else {
            add(ls(id), l, mid, x);
            add(rs(id), mid + 1, r, x);
        }
        push_up(id);
    }

    ll query(int id, int l, int r)
    {
        if (tree[id].l == l and tree[id].r == r) {
            return tree[id].sum;
        }
        push_down(id);
        int mid = (tree[id].l + tree[id].r) >> 1;
        if (r <= mid) {
            return query(ls(id), l, r);
        }
        if (l > mid) {
            return query(rs(id), l, r);
        }
        return (query(ls(id), l, mid) + query(rs(id), mid + 1, r)) % mod;
    }
    
    Fancy()
    {
        tot = 0;
        build(1, 1, maxn);
    }
    
    void append(int val)
    {
        ++tot;
        add(1, tot, tot, val);
    }
    
    void addAll(int inc)
    {
        if (tot) {
            add(1, 1, tot, inc);
        }
    }
    
    void multAll(int m)
    {
        if (tot) {
            mult(1, 1, tot, m);
        }
    }
    
    int getIndex(int idx)
    {
        if (idx + 1 > tot) {
            return -1;
        }
        return (int)query(1, idx + 1, idx + 1);
    }
};

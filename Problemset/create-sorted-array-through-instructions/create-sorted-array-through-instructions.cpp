
// @Title: 通过指令创建有序数组 (Create Sorted Array through Instructions)
// @Author: Singularity0909
// @Date: 2020-11-08 11:15:15
// @Runtime: 1140 ms
// @Memory: 117.1 MB

class SegmentTree {
private:
    struct node {
        int l, r, v;
    } tree[410000];

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
    SegmentTree tree;
    
    int createSortedArray(vector<int>& instructions)
    {
        vector<int> nums;
        tree.build(1, 1, 100000);
        const int mod(1e9 + 7);
        int sum = 0;
        for (int x : instructions) {
            int c1 = 0, c2 = 0;
            if (x > 1) {
                c1 = tree.query(1, 1, x - 1);
            }
            if (x < 100000) {
                c2 = tree.query(1, x + 1, 100000);
            }
            tree.insert(1, x);
            sum = (sum + min(c1, c2)) % mod;
        }
        return sum;
    }
};

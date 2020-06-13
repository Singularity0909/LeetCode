// Version 1 difference
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int* sum = new int[arr.size() + 1];
        sum[0] = 0;
        for (size_t i = 1; i <= arr.size(); i++)
            sum[i] = sum[i - 1] ^ arr[i - 1];
        vector<int> ans;
        for (auto each : queries) {
            int l = each[0] + 1, r = each[1] + 1;
            ans.push_back(sum[r] ^ sum[l - 1]);
        }
        return ans;
    }
};

// Version 2 segment-tree
class Solution {
public:
    int cnt;
    vector<int> arr;
    struct node { int l, r, v; } *tree;
    
    inline int ls(int id) { return id << 1; }
    
    inline int rs(int id) { return id << 1 | 1; }
    
    void push_up(int id) { tree[id].v = tree[ls(id)].v ^ tree[rs(id)].v; }
    
    void build(int id, int l, int r) {
        if ((tree[id].l = l) == (tree[id].r = r)) {
            tree[id].v = arr[cnt++];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(id), l, mid);
        build(rs(id), mid + 1, r);
        push_up(id);
    }
    
    int query(int id, int l, int r) {
        if (tree[id].l == l && tree[id].r == r) return tree[id].v;
        int mid = (tree[id].l + tree[id].r) >> 1;
        if (r <= mid) return query(ls(id), l, r);
        if (l > mid) return query(rs(id), l, r);
        return query(ls(id), l, mid) ^ query(rs(id), mid + 1, r);
    }
    
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        this->arr = arr;
        this->tree = new node[(arr.size() + 1) << 2];
        vector<int> ans;
        build(1, 1, (int)arr.size());
        for (auto each : queries) {
            int l = each[0] + 1, r = each[1] + 1;
            ans.push_back(query(1, l, r));
        }
        return ans;
    }
};
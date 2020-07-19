
// @Title: 数组中的逆序对 (数组中的逆序对  LCOF)
// @Author: Singularity0909
// @Date: 2020-07-20 01:41:03
// @Runtime: 468 ms
// @Memory: 47.8 MB

class Solution {
public:
    vector<int> tree, _set;

    inline int lowbit(int x)
    {
        return x & -x;
    }

    void add(int p, int x, int n)
    {
        for (int i = p; i <= n; i += lowbit(i)) {
            tree[i] += x;
        }
    }

    int getSum(int x)
    {
        int sum = 0;
        for (int i = x; i; i -= lowbit(i)) {
            sum += tree[i];
        }
        return sum;
    }

    int getPos(int x) 
    {
        return int(lower_bound(_set.begin(), _set.end(), x) - _set.begin()) + 1;
    }
    
    int reversePairs(vector<int>& nums) 
    {
        int sum = 0;
        for (int x : nums) _set.push_back(x);
        sort(_set.begin(), _set.end());
        _set.erase(unique(_set.begin(), _set.end()), _set.end());
        int n = (int)_set.size();
        tree.resize(n + 1);
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            int pos = getPos(nums[i]);
            add(pos, 1, n);
            sum += getSum(pos - 1);
        }
        return sum;
    }
};

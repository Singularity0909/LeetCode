
// @Title: 数字游戏 (数字游戏)
// @Author: Singularity0909
// @Date: 2020-11-03 11:10:28
// @Runtime: 712 ms
// @Memory: 70.6 MB

class Solution {
public:
    using ll = long long;
    const int mod = 1e9 + 7;
    ll sum1, sum2;
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    
    void balance() {
        if (max_heap.size() + 1 == min_heap.size()) {
            int x = min_heap.top();
            max_heap.push(x);
            min_heap.pop();
            sum1 += x;
            sum2 -= x;
        }
        else if (max_heap.size() > min_heap.size() + 1) {
            int x = max_heap.top();
            min_heap.push(x);
            max_heap.pop();
            sum1 -= x;
            sum2 += x;
        }
    }
    
    void push(int x) {
        if (max_heap.empty() or x <= max_heap.top()) {
            max_heap.push(x);
            sum1 += x;
        }
        else {
            min_heap.push(x);
            sum2 += x;
        }
        balance();
    }
    
    vector<int> numsGame(vector<int>& nums) {
        vector<int> res;
        size_t n = nums.size();
        for (int i = 0; i < n; i++) {
            push(nums[i] -= i);
            ll mid = max_heap.top();
            ll a = mid * (int)max_heap.size() - sum1;
            ll b = (sum2 - mid * (int)min_heap.size());
            res.push_back((a + b + mod) % mod);
        }
        return res;
    }
};

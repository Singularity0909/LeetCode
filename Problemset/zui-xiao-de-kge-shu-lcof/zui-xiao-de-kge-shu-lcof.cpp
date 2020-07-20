
// @Title: 最小的k个数 (最小的k个数  LCOF)
// @Author: Singularity0909
// @Date: 2020-07-21 01:24:40
// @Runtime: 132 ms
// @Memory: 20.2 MB

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) return {};
        priority_queue<int> q;
        for (int x : arr) {
            if (q.size() < k) q.push(x);
            else if (x < q.top()) {
                q.pop();
                q.push(x);
            }
        }
        vector<int> v;
        while (!q.empty()) {
            v.push_back(q.top());
            q.pop();
        }
        return v;
    }
};

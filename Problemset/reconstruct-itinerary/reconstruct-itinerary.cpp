
// @Title: 重新安排行程 (Reconstruct Itinerary)
// @Author: Singularity0909
// @Date: 2020-08-27 21:19:00
// @Runtime: 64 ms
// @Memory: 14.9 MB

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;
    vector<string> stk;

    void dfs(const string& curr) {
        while (vec.count(curr) && vec[curr].size() > 0) {
            string tmp = vec[curr].top();
            vec[curr].pop();
            dfs(move(tmp));
        }
        stk.emplace_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& it : tickets) {
            vec[it[0]].emplace(it[1]);
        }
        dfs("JFK");
        reverse(stk.begin(), stk.end());
        return stk;
    }
};

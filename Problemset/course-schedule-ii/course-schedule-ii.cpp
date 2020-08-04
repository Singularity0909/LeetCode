
// @Title: 课程表 II (Course Schedule II)
// @Author: Singularity0909
// @Date: 2020-08-04 00:31:26
// @Runtime: 32 ms
// @Memory: 12.8 MB

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> deg(numCourses);
        vector<vector<int>> edges(numCourses);
        for (auto edge : prerequisites) {
            deg[edge.at(0)]++;
            edges[edge.at(1)].push_back(edge.at(0));
        }
        queue<int> q;
        vector<int> res;
        for (int i = 0; i < numCourses; i++) {
            if (!deg.at(i)) {
                q.push(i);
                res.push_back(i);
            }
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int nxt : edges.at(now)) {
                if (!--deg.at(nxt)) {
                    q.push(nxt);
                    res.push_back(nxt);
                }
            }
        }
        if (res.size() == numCourses) return res;
        return {};
    }
};

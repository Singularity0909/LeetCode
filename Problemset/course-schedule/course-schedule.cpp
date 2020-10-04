
// @Title: 课程表 (Course Schedule)
// @Author: Singularity0909
// @Date: 2020-08-04 00:27:46
// @Runtime: 28 ms
// @Memory: 12.2 MB

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> deg(numCourses);
        vector<vector<int>> edges(numCourses);
        for (auto edge : prerequisites) {
            deg[edge.at(0)]++;
            edges[edge.at(1)].push_back(edge.at(0));
        }
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < numCourses; i++) {
            if (!deg.at(i)) {
                q.push(i);
                cnt++;
            }
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int nxt : edges.at(now)) {
                if (!--deg.at(nxt)) {
                    q.push(nxt);
                    cnt++;
                }
            }
        }
        return cnt == numCourses;
    }
};

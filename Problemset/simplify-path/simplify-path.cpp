
// @Title: 简化路径 (Simplify Path)
// @Author: Singularity0909
// @Date: 2020-10-03 22:16:22
// @Runtime: 8 ms
// @Memory: 8 MB

class Solution {
public:
    string simplifyPath(string path)
    {
        deque<string> dq;
        queue<string> q;
        string tmp, res;
        for (char c : path) {
            if (!tmp.empty() and c == '/') {
                q.push(tmp);
                tmp.clear();
            } else if (c != '/') {
                tmp.push_back(c);
            }
        }
        if (!tmp.empty()) {
            q.push(tmp);
        }
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            if (tmp == ".") {
                continue;
            } else if (tmp == ".." and !dq.empty()) {
                dq.pop_back();
            } else if (tmp != "..") {
                dq.push_back(tmp);
            }
        }
        while (!dq.empty()) {
            res += "/" + dq.front();
            dq.pop_front();
        }
        return res.empty() ? "/" : res;
    }
};

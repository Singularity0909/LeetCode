
// @Title: 文件夹操作日志搜集器 (Crawler Log Folder)
// @Author: Singularity0909
// @Date: 2020-09-27 12:11:48
// @Runtime: 8 ms
// @Memory: 10.2 MB

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for (const string& s : logs) {
            if (s[0] != '.') cnt++;
            else if (s.size() == 3 && cnt) cnt--;
        }
        return cnt;
    }
};

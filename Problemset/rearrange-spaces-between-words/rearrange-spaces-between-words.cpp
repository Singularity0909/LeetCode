
// @Title: 重新排列单词间的空格 (Rearrange Spaces Between Words)
// @Author: Singularity0909
// @Date: 2020-09-20 20:02:48
// @Runtime: 0 ms
// @Memory: 6.1 MB

class Solution {
public:
    string reorderSpaces(string text) {
        int cnt = 0;
        for (char c : text) {
            if (c == ' ') {
                cnt++;
            }
        }
        stringstream ss(text);
        string str, res;
        vector<string> vec;
        while (ss >> str) vec.push_back(str);
        if (vec.size() == 1) return vec.front() + string(cnt, ' ');
        int gap = cnt / (vec.size() - 1);
        int rem = cnt - gap * (vec.size() - 1);
        for (int i = 0; i < (int)vec.size(); i++) {
            res += vec[i] + string(i == vec.size() - 1 ? rem : gap, ' ');
        }
        return res;
    }
};

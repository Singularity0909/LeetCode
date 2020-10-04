
// @Title: 匹配子序列的单词数 (Number of Matching Subsequences)
// @Author: Singularity0909
// @Date: 2020-07-27 00:18:30
// @Runtime: 384 ms
// @Memory: 39.5 MB

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<int> pos[26];
        for (int i = 0; i < (int)S.length(); i++) pos[S[i] - 'a'].push_back(i);
        int cnt = 0;
        for (string& word : words) {
            int last = -1;
            bool flag = false;
            for (char c : word) {
                int i = c - 'a';
                int p = int(upper_bound(pos[i].begin(), pos[i].end(), last) - pos[i].begin());
                if (p != pos[i].size()) last = pos[i][p];
                else {
                    flag = true;
                    break;
                }
            }
            cnt += !flag;
        }
        return cnt;
    }
};


// @Title: 单词接龙 (Word Ladder)
// @Author: Singularity0909
// @Date: 2020-10-16 09:16:30
// @Runtime: 324 ms
// @Memory: 14.5 MB

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        int n = (int)wordList.size() + 1;
        vector<vector<int>> edges(n);
        unordered_map<string, int> mp;
        mp[beginWord] = 0;
        for (int i = 1; i <= n - 1; ++i) {
            mp[wordList[i - 1]] = i;
        }
        if (mp.find(endWord) == mp.end()) {
            return 0;
        }
        int m = (int)beginWord.length();
        for (int i = 0; i < m; ++i) {
            char tmp = beginWord[i];
            for (int j = 0; j < 26; ++j) {
                if (tmp == 'a' + j) {
                    continue;
                }
                beginWord[i] = 'a' + j;
                if (mp.find(beginWord) != mp.end()) {
                    edges[0].push_back(mp[beginWord]);
                }
                beginWord[i] = tmp;
            }
        }
        for (int i = 1; i <= n - 1; ++i) {
            string& word = wordList[i - 1];
            for (int j = 0; j < m; ++j) {
                char tmp = word[j];
                for (int k = 0; k < 26; ++k) {
                    if (tmp == 'a' + k) {
                        continue;
                    }
                    word[j] = 'a' + k;
                    if (mp.find(word) != mp.end()) {
                        edges[i].push_back(mp[word]);
                    }
                    word[j] = tmp;
                }
            }
        }
        using p = pair<int, int>;
        queue<p> q;
        q.push(p(0, 0));
        vector<bool> vis(n, false);
        vis[0] = true;
        while (!q.empty()) {
            int cur = q.front().first;
            int step = q.front().second;
            if (cur and wordList[cur - 1] == endWord) {
                return step + 1;
            }
            q.pop();
            for (int nxt : edges[cur]) {
                if (not vis[nxt]) {
                    q.push(p(nxt, step + 1));
                    vis[nxt] = true;
                }
            }
        }
        return 0;
    }
};

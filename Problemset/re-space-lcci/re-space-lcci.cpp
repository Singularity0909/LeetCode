
// @Title: 恢复空格 (Re-Space LCCI)
// @Author: Singularity0909
// @Date: 2020-07-15 14:35:01
// @Runtime: 136 ms
// @Memory: 97.8 MB

class Trie {
public:
    int cnt;
    int** trie;
    bool* exist;
    
    Trie(int n) {
        cnt = 0;
        trie = new int*[n];
        exist = new bool[n];
        for (int i = 0; i < n; i++) {
            exist[i] = false;
            trie[i] = new int[26];
            for (int j = 0; j < 26; j++) {
                trie[i][j] = 0;
            }
        }
    }
    
    void insert(string s) {
        int u = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[u][c]) u = trie[u][c];
            else u = trie[u][c] = ++cnt;
        }
        exist[u] = true;
    }
};

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int sum = 0;
        for (string str : dictionary) {
            sum += str.length() + 1;
        }
        Trie* trie = new Trie(sum);
        for (string str : dictionary) {
            trie->insert(string(str.rbegin(), str.rend()));
        }
        size_t n = sentence.length();
        vector<int> dp(n + 1, 0);
        sentence.insert(0, " ");
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            int u = 0;
            for (int j = i; j >= 1; j--) {
                int c = sentence[j] - 'a';
                u = trie->trie[u][c];
                if (!u) break;
                if (trie->exist[u]) {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
            }
        }
        return dp[n];
    }
};


// @Title: 排列序列 (Permutation Sequence)
// @Author: Singularity0909
// @Date: 2020-09-06 20:59:01
// @Runtime: 0 ms
// @Memory: 6.1 MB

class Solution {
public:
    string getPermutation(int n, int k) {
        using p = pair<int, int>;
        vector<int> fac(n);
        vector<bool> vis(n + 1, false);
        fac[0] = 1;
        for (int i = 1; i < n; ++i) {
            fac[i] = fac[i - 1] * i;
        }
        --k;
        string str, ans;
        queue<p> rep;
        while (k) {
            int pos = int(upper_bound(fac.begin(), fac.end(), k) - fac.begin()) - 1;
            int num = k / fac[pos];
            rep.push(p(n - pos - 1, num));
            k -= fac[pos] * num;
        }
        for (int i = 0; i < n; i++) {
            if (i == rep.front().first) {
                for (int j = 1; j <= n; j++) {
                    if (!vis[j] && !rep.front().second--) {
                        vis[j] = true;
                        ans.push_back(j + 48);
                        break;
                    }
                }
                rep.pop();
            }
            else {
                for (int j  = 1; j <= n; j++) {
                    if (!vis[j]) {
                        vis[j] = true;
                        ans.push_back(j + 48);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

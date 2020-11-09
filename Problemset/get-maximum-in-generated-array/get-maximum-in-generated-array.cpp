
// @Title: 获取生成数组中的最大值 (Get Maximum in Generated Array)
// @Author: Singularity0909
// @Date: 2020-11-08 10:34:34
// @Runtime: 4 ms
// @Memory: 6.7 MB

class Solution {
public:
    int getMaximumGenerated(int n)
    {
        vector<int> vec(n + 1, 0);
        vec[0] = 0;
        if (n) vec[1] = 1;
        for (int i = 0; i <= n; ++i) {
            if (i * 2 >= 2 and i * 2 <= n) {
                vec[i * 2] = vec[i];
            }
            if (i * 2 + 1 >= 2 and i * 2 + 1 <= n) {
                vec[i * 2 + 1] = vec[i] + vec[i + 1];
            }
        }
        return *max_element(vec.begin(), vec.end());
    }
};

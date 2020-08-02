
// @Title: 统计好三元组 (Count Good Triplets)
// @Author: Singularity0909
// @Date: 2020-08-02 13:11:26
// @Runtime: 52 ms
// @Memory: 8.4 MB

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        size_t n = arr.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

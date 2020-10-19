
// @Title: 删除某些元素后的数组均值 (Mean of Array After Removing Some Elements)
// @Author: Singularity0909
// @Date: 2020-10-17 22:33:48
// @Runtime: 20 ms
// @Memory: 9.6 MB

class Solution {
public:
    double trimMean(vector<int>& arr)
    {
        int n = (int)arr.size();
        sort(arr.begin(), arr.end());
        int m = n / 20;
        double sum = 0;
        for (int i = m; i < n - m; ++i) {
            sum += arr[i];
        }
        return sum / (n - m * 2);
    }
};

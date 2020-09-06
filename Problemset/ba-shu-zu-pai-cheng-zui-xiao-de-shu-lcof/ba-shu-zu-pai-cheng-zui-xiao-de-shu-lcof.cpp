
// @Title: 把数组排成最小的数 (把数组排成最小的数 LCOF)
// @Author: Singularity0909
// @Date: 2020-09-04 02:37:41
// @Runtime: 12 ms
// @Memory: 11.8 MB

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> vec;
        for (int x : nums) {
            vec.push_back(to_string(x));
        }
        auto cmp = [&](const string& a, const string& b) -> bool {
            return a + b < b + a;
        };
        sort(vec.begin(), vec.end(), cmp);
        string res;
        for (string& each : vec) res += each;
        return res;
    }
};

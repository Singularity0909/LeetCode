
// @Title: 警告一小时内使用相同员工卡大于等于三次的人 (Alert Using Same Key-Card Three or More Times in a One Hour Period)
// @Author: Singularity0909
// @Date: 2020-10-04 22:37:51
// @Runtime: 796 ms
// @Memory: 100.3 MB

class Solution {
public:
    inline int cal(const string& s)
    {
        return 10 * 60 * (s[0] - '0') + 60 * (s[1] - '0') + 10 * (s[3] - '0') + s[4] - '0';
    }

    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime)
    {
        map<string, vector<int>> mp;
        int n = (int)keyName.size();
        for (int i = 0; i < n; i++) {
            mp[keyName[i]].push_back(cal(keyTime[i]));
        }
        set<string> ans;
        for (auto each : mp) {
            auto& vec = each.second;
            sort(vec.begin(), vec.end());
            int n = (int)vec.size();
            for (int i = 2; i < n; i++) {
                if (vec[i] - vec[i - 2] <= 60) {
                    ans.insert(each.first);
                }
            }
        }
        vector<string> res;
        for (auto& each : ans) {
            res.push_back(each);
        }
        return res;
    }
};

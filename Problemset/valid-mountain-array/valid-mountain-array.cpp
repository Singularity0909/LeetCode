
// @Title: 有效的山脉数组 (Valid Mountain Array)
// @Author: Singularity0909
// @Date: 2020-11-03 00:36:46
// @Runtime: 52 ms
// @Memory: 21.1 MB

class Solution {
public:
    int getMaxIndex(vector<int>& vec)
    {
        for (int i = 0; i < (int)vec.size() - 1; ++i) {
            if (vec[i] >= vec[i + 1]) {
                return i;
            }
        }
        return (int)vec.size() - 1;
    }

    int getMinIndex(vector<int>& vec)
    {
        for (int i = (int)vec.size() - 1; i; --i) {
            if (vec[i] >= vec[i - 1]) {
                return i;
            }
        }
        return 0;
    }

    bool validMountainArray(vector<int>& vec)
    {
        if (vec.empty()) {
            return false;
        }
        int mx = getMaxIndex(vec);
        int mn = getMinIndex(vec);
        return mx == mn and mx > 0 and mx < vec.size() - 1;
    }
};

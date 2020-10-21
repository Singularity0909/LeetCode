
// @Title: 长按键入 (Long Pressed Name)
// @Author: Singularity0909
// @Date: 2020-10-21 20:35:44
// @Runtime: 0 ms
// @Memory: 6.3 MB

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (j < typed.length()) {
            if (i < name.length() && name[i] == typed[j]) {
                ++i;
                ++j;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                ++j;
            } else {
                return false;
            }
        }
        return i == name.length();
    }
};

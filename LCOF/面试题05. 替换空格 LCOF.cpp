class Solution {
public:
    string replaceSpace(string s) {
        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                s.erase(i, 1);
                s.insert(i, "%20");
                i += 2;
            }
        }
        return s;
    }
};
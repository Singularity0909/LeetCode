
// @Title: 字母组合迭代器 (Iterator for Combination)
// @Author: Singularity0909
// @Date: 2020-10-10 09:29:18
// @Runtime: 24 ms
// @Memory: 11.6 MB

class CombinationIterator {
public:
    int num;
    int cur;
    string str;
    
    CombinationIterator(string characters, int combinationLength)
    {
        cur = (1 << characters.length()) - 1;
        num = combinationLength;
        str = characters;
    }
    
    int getDigits(int n)
    {
        int cnt = 0;
        while (n) {
            n &= (n - 1);
            ++cnt;
        }
        return cnt;
    }
    
    string next()
    {
        int len = (int)str.length();
        for (int i = cur - 1; i; --i) {
            if (getDigits(i) != num) continue;
            string nxt;
            cur = i;
            int p = 0;
            while (i) {
                if (i & 1) {
                    nxt.push_back(str[len - p - 1]);
                }
                ++p;
                i >>= 1;
            }
            reverse(nxt.begin(), nxt.end());
            return nxt;
        }
        return string();
    }
    
    bool hasNext()
    {
        for (int i = cur - 1; i; --i) {
            if (getDigits(i) == num) {
                return true;
            }
        }
        return false;
    }
};

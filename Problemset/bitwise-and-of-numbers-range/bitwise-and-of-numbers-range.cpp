
// @Title: 数字范围按位与 (Bitwise AND of Numbers Range)
// @Author: Singularity0909
// @Date: 2020-08-23 11:30:41
// @Runtime: 12 ms
// @Memory: 5.7 MB

// Version 1
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int cnt = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            cnt++;
        }
        return n << cnt;
    }
};

// Version 2
// class Solution {
// public:
//     int rangeBitwiseAnd(int m, int n) {
//         int res = 0;
//         using ll = long long;
//         for (int i = 0; i < 32; i++) {
//             ll range = 1ll << i, mod = 1ll << i << 1;
//             if (((ll)n - m + 1) <= range && (m & (mod - 1)) >= range && (n & (mod - 1)) >= range)
//                 res |= 1 << i;
//         }
//         return res;
//     }
// };

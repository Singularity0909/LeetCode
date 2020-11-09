
// @Title: 销售价值减少的颜色球 (Sell Diminishing-Valued Colored Balls)
// @Author: Singularity0909
// @Date: 2020-11-08 11:32:55
// @Runtime: 452 ms
// @Memory: 63.8 MB

class Solution {
public:
    using ll = long long;
    
    inline ll func(ll x)
    {
        return x * (x + 1) / 2;
    }
    
    int maxProfit(vector<int>& inventory, int orders)
    {
        const int mod(1e9 + 7);
        inventory.emplace_back(0);
        sort(inventory.begin(), inventory.end(), greater<int>());
        ll sum = 0;
        size_t siz = inventory.size();
        for (int i = 1; i < siz; ++i) {
            int tmp = 1ll * (inventory[i - 1] - inventory[i]) * i;
            if (orders <= tmp) {
                sum = (sum + 1ll * i * (func(inventory[i - 1]) - func(inventory[i - 1] - orders / i)) + mod) % mod;
                sum = (sum + 1ll * (orders % i) * (inventory[i - 1] - orders / i)) % mod;
                return (int)sum;
            } else {
                orders -= tmp;
                sum = (sum + 1ll * i * (func(inventory[i - 1]) - func(inventory[i])) % mod + mod) % mod;
            }
        }
        return (int)sum;
    }
};

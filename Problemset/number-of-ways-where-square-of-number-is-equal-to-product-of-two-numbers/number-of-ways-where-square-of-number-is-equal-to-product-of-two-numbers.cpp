
// @Title: 数的平方等于两数乘积的方法数 (Number of Ways Where Square of Number Is Equal to Product of Two Numbers)
// @Author: Singularity0909
// @Date: 2020-09-06 17:13:12
// @Runtime: 76 ms
// @Memory: 11.6 MB

class Solution {
public:
    using ll = long long;
    
    ll getDiv(ll a, ll b) {
        ll res = a / b;
        return res * b == a ? res : -1;
    }
    
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        using p = pair<ll, ll>;
        map<ll, int> map1, map2;
        set<ll> vis;
        for (ll x : nums1) map1[x]++;
        for (ll x : nums2) map2[x]++;
        ll sum = 0;
        for (auto each : map1) {
            ll x = each.first, y = each.second;
            vis.clear();
            for (auto _each : map2) {
                if (vis.find(_each.first) != vis.end()) {
                    continue;
                }
                ll ano = getDiv(x * x, _each.first);
                if (ano == -1) continue;
                if (map2.find(ano) == map2.end()) {
                    continue;
                }
                if (ano == _each.first) {
                    sum += y * _each.second * (_each.second - 1) / 2;
                }
                else {
                    sum += y * _each.second * map2[ano];
                }
                vis.insert(_each.first);
                vis.insert(ano);
            }
        }
        
        for (auto each : map2) {
            ll x = each.first, y = each.second;
            vis.clear();
            for (auto _each : map1) {
                if (vis.find(_each.first) != vis.end()) {
                    continue;
                }
                ll ano = getDiv(x * x, _each.first);
                if (ano == -1) continue;
                if (map1.find(ano) == map1.end()) {
                    continue;
                }
                if (ano == _each.first) {
                    sum += y * _each.second * (_each.second - 1) / 2;
                }
                else {
                    sum += y * _each.second * map1[ano];
                }
                vis.insert(_each.first);
                vis.insert(ano);
            }
        }
        
        return sum;
    }
};

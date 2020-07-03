class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        bool* vis = new bool[nums.size()];
        for (size_t i = 0; i < nums.size(); i++)
            vis[i] = false;
        for (int v : nums) {
            if (vis[v])
                return v;
            vis[v] = true;
        }
        return -1;
    }
};
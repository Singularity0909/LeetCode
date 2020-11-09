
// @Title: O(1) 时间插入、删除和获取随机元素 - 允许重复 (Insert Delete GetRandom O(1) - Duplicates allowed)
// @Author: Singularity0909
// @Date: 2020-10-31 10:52:26
// @Runtime: 96 ms
// @Memory: 26.7 MB

class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> idx;
    vector<int> nums;

    RandomizedCollection() {}
    
    bool insert(int val)
    {
        nums.push_back(val);
        idx[val].insert((int)nums.size() - 1);
        return idx[val].size() == 1;
    }
    
    bool remove(int val)
    {
        if (idx.find(val) == idx.end()) {
            return false;
        }
        int i = *(idx[val].begin());
        nums[i] = nums.back();
        idx[val].erase(i);
        idx[nums[i]].erase((int)nums.size() - 1);
        if (i < nums.size() - 1) {
            idx[nums[i]].insert(i);
        }
        if (idx[val].size() == 0) {
            idx.erase(val);
        }
        nums.pop_back();
        return true;
    }
    
    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};

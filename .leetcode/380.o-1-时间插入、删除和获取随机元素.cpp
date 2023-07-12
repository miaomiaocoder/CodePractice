/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
// 哈希表加变长数组
class RandomizedSet {
    unordered_map<int, int> hash;
    vector<int> nums;

   public:
    RandomizedSet() {}

    bool insert(int val) {
        if (hash.count(val) == 0) {
            nums.emplace_back(val);
            hash[val] = nums.size() - 1;
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (hash.count(val)) {
            int y = nums.back();
            int p1 = hash[val], p2 = hash[y];
            swap(nums[p1], nums[p2]);
            swap(hash[val], hash[y]);
            nums.pop_back();
            hash.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() { return nums[rand() % nums.size()]; }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

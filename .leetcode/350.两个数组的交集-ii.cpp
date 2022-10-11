/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
// 使用unordered_map
class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> hash;
        for (int x : nums1) hash[x]++;
        for (int y : nums2)
            if (hash[y] > 0) {
                res.push_back(y);
                hash[y]--;
            }
        return res;
    }
};

// 使用unordered_multiset
class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_multiset<int> S;
        for (auto& x : nums1) S.insert(x);
        for (auto& x : nums2)
            if (S.count(x)) {
                res.push_back(x);
                S.erase(S.find(x));  // 不可写成S.erase(x), 会删除所有x
            }
        return res;
    }
};
// @lc code=end

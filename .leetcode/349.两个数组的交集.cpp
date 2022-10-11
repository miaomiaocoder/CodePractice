/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> S;
        for (auto& x : nums1) S.insert(x);
        for (auto& x : nums2)
            if (S.count(x)) {
                res.push_back(x);
                S.erase(x);
            }
        return res;
    }
};
// @lc code=end

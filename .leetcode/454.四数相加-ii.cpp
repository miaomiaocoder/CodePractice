/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
   public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        unordered_map<int, int> hash;
        int res = 0;
        for (auto& a : nums1)
            for (auto& b : nums2) hash[a + b]++;

        for (auto& c : nums3)
            for (auto& d : nums4) res += hash[-(c + d)];

        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> s(nums.size() + 1);
        for (int i = 1; i <= nums.size(); ++i) s[i] = s[i - 1] + nums[i - 1];
        unordered_map<int, int> hash;
        hash[0] = 1;
        int res = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            res += hash[s[i] - k];
            hash[s[i]]++;
        }
        return res;
    }
};
// @lc code=end

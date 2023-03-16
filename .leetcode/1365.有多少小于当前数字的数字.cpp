/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start
class Solution {
   public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());

        unordered_map<int, int> hash;
        for (int i = vec.size() - 1; i >= 0; --i) {
            hash[vec[i]] = i;
        }

        for (int i = 0; i < vec.size(); ++i) {
            vec[i] = hash[nums[i]];
        }
        return vec;
    }
};
// @lc code=end

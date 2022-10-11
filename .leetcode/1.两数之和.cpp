/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hash;
        for (int i = 0; i <= nums.size(); i++) {
            int r = target - nums[i];
            if (hash.count(r)) {
                res.push_back(hash[r]);
                res.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }
        return res;
    }
};

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int r = target - nums[i];
            if (hash.count(r)) return {hash[r], i};
            hash[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

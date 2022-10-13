/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                for (int k = j + 1, u = nums.size() - 1; k < u; k++) {
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    while (u - 1 > k &&
                           (long)nums[i] + nums[j] + nums[k] + nums[u - 1] >=
                               target)
                        u--;
                    if ((long)nums[i] + nums[j] + nums[k] + nums[u] == target)
                        res.push_back({nums[i], nums[j], nums[k], nums[u]});
                }
            }
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& nums, int start) {
        res.emplace_back(path);
        if (start >= nums.size()) return;

        for (int i = start; i < nums.size(); i++) {
            path.emplace_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};
// @lc code=end

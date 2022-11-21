/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& nums, int start, vector<int>& used) {
        res.emplace_back(path);
        if (start >= nums.size()) return;

        for (int i = start; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0) {
                continue;
            }
            path.emplace_back(nums[i]);
            used[i] = 1;
            backtrack(nums, i + 1, used);
            used[i] = 0;
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> used(nums.size(), 0);
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, used);
        return res;
    }
};
// @lc code=end

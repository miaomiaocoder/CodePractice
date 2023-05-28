/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(vector<int>& nums, vector<int>& used) {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] == 1) continue;
            path.emplace_back(nums[i]);
            used[i] = 1;
            backtrack(nums, used);
            used[i] = 0;
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(), 0);
        res.clear();
        path.clear();
        backtrack(nums, used);
        return res;
    }
};
// @lc code=end

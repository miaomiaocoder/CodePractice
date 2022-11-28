/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& nums, int (&used)[21]) {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == 1) continue;
            used[i] = 1;
            path.emplace_back(nums[i]);
            backtrack(nums, used);
            path.pop_back();
            used[i] = 0;
        }
    }

   public:
    vector<vector<int>> permute(vector<int>& nums) {
        int used[21] = {0};
        backtrack(nums, used);
        return res;
    }
};
// @lc code=end

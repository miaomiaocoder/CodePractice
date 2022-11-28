/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
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
            if (used[i] == 1 ||
                (i && nums[i] == nums[i - 1] && used[i - 1] == 0))
                continue;
            used[i] = 1;
            path.emplace_back(nums[i]);
            backtrack(nums, used);
            path.pop_back();
            used[i] = 0;
        }
    }

   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int used[21] = {0};
        backtrack(nums, used);
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
// 使用数组模拟set来对同一节点下本层去重
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& nums, int start) {
        if (path.size() >= 2) res.emplace_back(path);
        if (start >= nums.size()) return;
        // 这里使用数组来进行去重操作，题目说数值范围[-100, 100]
        int uset[201] = {0};
        for (int i = start; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) ||
                uset[nums[i] + 100] == 1)
                continue;
            // 记录这个元素在本层用过了，本层后面不能再用了
            uset[nums[i] + 100] = 1;
            path.emplace_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};

// 使用set来对同一节点下本层去重
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(vector<int>& nums, int start) {
        if (path.size() >= 2) {
            res.emplace_back(path);
            // 注意这里不要加return，要取树上的节点
        }
        unordered_set<int> uset;  // 使用set对本层元素进行去重
        for (int i = start; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) ||
                uset.find(nums[i]) != uset.end()) {
                continue;
            }
            // 记录这个元素在本层用过了，本层后面不能再用了
            uset.insert(nums[i]);
            path.emplace_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};
// @lc code=end

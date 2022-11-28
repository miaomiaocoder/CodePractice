/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
// 使用used数组去重
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;

    void getCombinations(vector<int>& candidates, int target, int idx, int sum,
                         vector<int>& used) {
        if (sum == target) {
            res.emplace_back(path);
            return;
        }

        for (int i = idx;
             i < candidates.size() && sum + candidates[i] <= target; ++i) {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == 0)
                continue;
            sum += candidates[i];
            path.emplace_back(candidates[i]);
            used[i] = 1;
            getCombinations(candidates, target, i + 1, sum, used);
            used[i] = 0;
            path.pop_back();
            sum -= candidates[i];
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> used(candidates.size(), 0);
        sort(candidates.begin(), candidates.end());
        getCombinations(candidates, target, 0, 0, used);
        return res;
    }
};

// 使用set来对同一节点下本层去重
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& candidates, int target, int idx, int sum) {
        if (sum == target) {
            res.emplace_back(path);
            return;
        }
        if (idx >= candidates.size()) return;

        unordered_set<int> uset;
        for (int i = idx;
             i < candidates.size() && sum + candidates[i] <= target; i++) {
            if (uset.find(candidates[i]) != uset.end()) continue;
            uset.insert(candidates[i]);
            sum += candidates[i];
            path.emplace_back(candidates[i]);
            backtrack(candidates, target, i + 1, sum);
            path.pop_back();
            sum -= candidates[i];
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;

    void getCombinations(vector<int>& candidates, int target, int idx) {
        int sum = 0;
        for (int x : path) sum += x;
        if (sum > target) return;
        if (sum == target) {
            res.emplace_back(path);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            path.emplace_back(candidates[i]);
            getCombinations(candidates, target, i);
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        getCombinations(candidates, target, 0);
        return res;
    }
};

class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;

    void getCombinations(vector<int>& candidates, int target, int idx,
                         int sum) {
        if (sum > target) return;
        if (sum == target) {
            res.emplace_back(path);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            sum += candidates[i];
            path.emplace_back(candidates[i]);
            getCombinations(candidates, target, i, sum);
            path.pop_back();
            sum -= candidates[i];
        }
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        getCombinations(candidates, target, 0, 0);
        return res;
    }
};

// 先排序，再做剪枝优化
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;

    void getCombinations(vector<int>& candidates, int target, int idx,
                         int sum) {
        if (sum == target) {
            res.emplace_back(path);
            return;
        }

        for (int i = idx;
             i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.emplace_back(candidates[i]);
            getCombinations(candidates, target, i, sum);
            path.pop_back();
            sum -= candidates[i];
        }
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        getCombinations(candidates, target, 0, 0);
        return res;
    }
};

// @lc code=end

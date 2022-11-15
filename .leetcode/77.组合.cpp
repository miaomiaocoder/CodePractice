/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
// 未优化版本
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int n, int k, int start) {
        if (k == path.size()) {
            res.emplace_back(path);
            return;
        }

        for (int i = start; i <= n; i++) {
            path.emplace_back(i);
            dfs(n, k, i + 1);
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return res;
    }
};

// 剪枝优化写法
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int n, int k, int start) {
        if (path.size() == k) {
            res.emplace_back(path);
            return;
        }

        for (int i = start; i <= n - (k - path.size()) + 1; i++) {
            path.emplace_back(i);
            dfs(n, k, i + 1);
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return res;
    }
};
// @lc code=end

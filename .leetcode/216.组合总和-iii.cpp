/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
// 第一种回溯写法
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int k, int n, int start) {
        int sum = 0;
        for (auto &x : path) sum += x;
        if (sum == n && path.size() == k) {
            res.emplace_back(path);
            return;
        }

        for (int i = start; i <= 9; i++) {
            path.emplace_back(i);
            dfs(k, n, i + 1);
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return res;
    }
};

// 第一种回溯剪枝优化
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int k, int n, int start) {
        if (path.size() > k) return;
        int sum = 0;
        for (auto &x : path) sum += x;
        if (sum == n && path.size() == k) {
            res.emplace_back(path);
            return;
        }

        for (int i = start; i <= 9 - (k - path.size()) + 1; i++) {
            path.emplace_back(i);
            dfs(k, n, i + 1);
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return res;
    }
};

// 第二种回溯写法
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int k, int n, int sum, int start) {
        if (sum == n && path.size() == k) {
            res.emplace_back(path);
            return;
        }

        for (int i = start; i <= 9; i++) {
            sum += i;
            path.emplace_back(i);
            dfs(k, n, sum, i + 1);
            path.pop_back();
            sum -= i;
        }
    }

   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 0, 1);
        return res;
    }
};

// 第二种回溯剪枝写法
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int k, int n, int sum, int start) {
        if (sum > n) return;

        if (sum == n && path.size() == k) {
            res.emplace_back(path);
            return;
        }

        for (int i = start; i <= 9 - (k - path.size()) + 1; i++) {
            sum += i;
            path.emplace_back(i);
            dfs(k, n, sum, i + 1);
            path.pop_back();
            sum -= i;
        }
    }

   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 0, 1);
        return res;
    }
};
// @lc code=end

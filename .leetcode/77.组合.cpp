/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
   private:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(int n, int k, int start) {
        if (k == path.size()) {
            result.push_back(path);
            return;
        }

        for (int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(n, k, i + 1);
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return result;
    }
};
// @lc code=end

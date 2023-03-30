/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
class Solution {
   private:
    vector<int> col, dg, udg;
    vector<vector<string>> res;
    vector<string> path;

    void backtrack(int u, int n) {
        if (u == n) {
            res.emplace_back(path);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
                col[i] = dg[u + i] = udg[n - u + i] = 1;
                path[u][i] = 'Q';
                backtrack(u + 1, n);
                path[u][i] = '.';
                col[i] = dg[u + i] = udg[n - u + i] = 0;
            }
        }
    }

   public:
    int totalNQueens(int n) {
        col = vector<int>(n, 0);
        dg = udg = vector<int>(n * 2, 0);
        path = vector<string>(n, string(n, '.'));
        backtrack(0, n);
        return res.size();
    }
};
// @lc code=end

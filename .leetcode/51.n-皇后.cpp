/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
// 斜率为1是计算离左上角点的曼哈顿距离 u + i
// 斜率为-1是计算离左下角点的哈曼顿距离 (n - u) + i
class Solution {
   private:
    vector<int> col, dg, udg;
    vector<vector<string>> res;
    vector<string> path;

    void backtrack(int u, int &n) {
        if (u == n) {
            res.emplace_back(path);
            return;
        }

        for (int i = 0; i < n; i++) {
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
    vector<vector<string>> solveNQueens(int n) {
        col = vector<int>(n, 0);
        dg = udg = vector<int>(n * 2, 0);
        path = vector<string>(n, string(n, '.'));

        backtrack(0, n);
        return res;
    }
};
// @lc code=end

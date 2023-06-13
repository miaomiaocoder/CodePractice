/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
    vector<vector<int>> g;

   public:
    int orangesRotting(vector<vector<int>>& grid) {
        g = grid;
        int m = g.size(), n = g[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (g[i][j] == 2) q.push({i, j});

        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

        int res = 0;
        // 注意这一步
        if (q.size()) res--;
        while (q.size()) {
            res++;
            int len = q.size();
            while (len--) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int x = t.first + dx[i], y = t.second + dy[i];
                    if (x < 0 || x >= m || y < 0 || y >= n || g[x][y] != 1)
                        continue;
                    g[x][y] = 2;
                    q.push({x, y});
                }
            }
        }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (g[i][j] == 1) return -1;
        return res;
    }
};
// @lc code=end

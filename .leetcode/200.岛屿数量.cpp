/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
   public:
    vector<vector<char>> g;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        int cnt = 0;
        for (int i = 0; i < g.size(); i++)
            for (int j = 0; j < g[i].size(); j++)
                if (g[i][j] == '1') {
                    dfs(i, j);
                    cnt++;
                }
        return cnt;
    }

    void dfs(int x, int y) {
        g[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < g.size() && b >= 0 && b < g[a].size() &&
                g[a][b] == '1')
                dfs(a, b);
        }
    }
};
// @lc code=end

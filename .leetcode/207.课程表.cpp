/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> edges = prerequisites;
        vector<vector<int>> g(n);
        vector<int> d(n);
        for (auto e : edges) {
            int b = e[0], a = e[1];
            g[a].push_back(b);
            d[b]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (d[i] == 0) q.push(i);

        int cnt = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            cnt++;
            for (auto i : g[t])
                if (--d[i] == 0) q.push(i);
        }

        return cnt == n;
    }
};
// @lc code=end

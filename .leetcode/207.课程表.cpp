/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
// 拓扑排序
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
            // 统计每个点入度
            d[b]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i)
            // 将入度为0的点插入队列
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

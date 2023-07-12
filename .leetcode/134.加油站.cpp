/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // 枚举起点
        for (int i = 0, j; i < n;) {
            int left = 0;
            // j 表示从 i 开始往后走多远
            for (j = 0; j < n; j++) {
                int k = (i + j) % n;
                left += gas[k] - cost[k];
                if (left < 0) break;
            }
            if (j == n) return i;
            i = i + j + 1;
        }
        return -1;
    }
};

class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0, j; i < n; i = i + j + 1) {
            int left = 0;
            for (j = 0; j < n; ++j) {
                int k = (i + j) % n;
                left += gas[k] - cost[k];
                if (left < 0) break;
            }
            if (j == n) return i;
        }
        return -1;
    };
}
// @lc code=end

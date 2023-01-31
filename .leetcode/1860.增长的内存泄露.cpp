/*
 * @lc app=leetcode.cn id=1860 lang=cpp
 *
 * [1860] 增长的内存泄露
 */

// @lc code=start
class Solution {
   public:
    vector<int> memLeak(int memory1, int memory2) {
        int t = 1;
        while (t <= max(memory1, memory2)) {
            if (memory1 < memory2)
                memory2 -= t;
            else
                memory1 -= t;
            t++;
        }
        return {t, memory1, memory2};
    }
};

// @lc code=end

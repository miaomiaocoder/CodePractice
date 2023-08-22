/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
   public:
    int rand10() {
        int t = (rand7() - 1) * 7 + rand7();
        if (t > 40) return rand10();
        return (t - 1) % 10 + 1;
    }
};
// @lc code=end

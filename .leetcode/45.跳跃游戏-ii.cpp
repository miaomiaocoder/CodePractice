/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
// https://www.acwing.com/solution/content/107/
class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 0);

        for (int i = 1, last = 0; i < n; i++) {
            while (last + nums[last] < i) last++;
            f[i] = f[last] + 1;
        }

        return f[n - 1];
    }
};
// @lc code=end

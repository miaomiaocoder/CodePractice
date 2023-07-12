/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
// 注意与45题区别
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true; // 只有一个元素，就是能达到
        for (int i = 0; i <= cover; i++) { // 注意这里是小于等于cover
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true; // 说明可以覆盖到终点了
        }
        return false;
    }
};


class Solution {
   public:
    bool canJump(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (j < i) return false;
            j = max(j, i + nums[i]);
        }
        return true;
    }
};
// @lc code=end

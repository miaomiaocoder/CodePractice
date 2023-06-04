/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int r, c = 0;
        for (int num : nums) {
            if (!c)
                r = num, c = 1;
            else if (r == num)
                c++;
            else
                c--;
        }
        return r;
    }
};
// @lc code=end

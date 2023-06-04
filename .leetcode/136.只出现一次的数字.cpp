/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
// 1.任何数和 0 做异或运算，结果仍然是原来的数
// 2.任何数和其自身做异或运算，结果是 0
// 3.异或运算满足交换律和结合律
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num: nums) res ^= num;
        return res;
    }
};
// @lc code=end


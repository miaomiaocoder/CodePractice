/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
// 第一步将小于等于0的数变成n + 1
// 第二步小于等于nums.size()对应位置变为负数
// 第三步返回第一个大于0的元素下标 + 1
// 注意范围for要使用引用，因为这里要修改nums
class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int& num : nums) {
            if (num <= 0) num = n + 1;
        }
        for (int i = 0; i < n; ++i) {
            // 注意这里要使用abs
            int num = abs(nums[i]);
            if (num <= n) nums[num - 1] = -abs(nums[num - 1]);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (auto &x: nums) {
            if (x <= 0) x = n + 1;
        }

        for (auto &x: nums) {
            int num = abs(x);
            if (num <= n) nums[num - 1] = -abs(nums[num - 1]);
        }

        for (int i = 0; i < n; ++i)
            if (nums[i] > 0) return i + 1;
        return n + 1;
    }
};

// @lc code=end

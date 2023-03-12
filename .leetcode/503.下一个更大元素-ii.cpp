/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nums1(nums.begin(), nums.end());
        nums.insert(nums.end(), nums1.begin(), nums1.end());
        vector<int> res(nums.size(), -1);
        stack<int> stk;
        stk.push(0);

        for (int i = 1; i < nums.size(); i++) {
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                res[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }

        res.resize(nums.size() / 2);
        return res;
    }
};

class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> stk;
        stk.push(0);

        for (int i = 1; i < nums.size() * 2; i++) {
            while (!stk.empty() && nums[i % nums.size()] > nums[stk.top()]) {
                res[stk.top()] = nums[i % nums.size()];
                stk.pop();
            }
            stk.push(i % nums.size());
        }

        res.resize(nums.size());
        return res;
    }
};
// @lc code=end

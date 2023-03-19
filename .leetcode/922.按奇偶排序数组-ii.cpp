/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution {
   public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> vec = nums;
        int odd = 1;
        int even = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                vec[even] = nums[i];
                even += 2;
            } else {
                vec[odd] = nums[i];
                odd += 2;
            }
        }
        return vec;
    }
};

class Solution {
   public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int oddIndex = 1;
        for (int i = 0; i < nums.size(); i += 2) {
            if (nums[i] % 2 == 1) {
                while (nums[oddIndex] % 2 != 0) oddIndex += 2;
                swap(nums[i], nums[oddIndex]);
            }
        }
        return nums;
    }
};

class Solution {
   public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for (int i = 0, j = 1; i < nums.size(); i += 2, j += 2) {
            while (i < nums.size() && nums[i] % 2 == 0) i += 2;
            while (j < nums.size() && nums[j] % 2 == 1) j += 2;
            if (i < nums.size()) swap(nums[i], nums[j]);
        }
        return nums;
    }
};
// @lc code=end

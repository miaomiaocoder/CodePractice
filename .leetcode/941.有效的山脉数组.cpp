/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
class Solution {
   public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int left = 0, right = arr.size() - 1;
        while (left < arr.size() - 1 && arr[left] < arr[left + 1]) ++left;

        while (right > 0 && arr[right - 1] > arr[right]) --right;

        if (left != 0 && right != arr.size() - 1 && left == right) return true;
        return false;
    }
};
// @lc code=end

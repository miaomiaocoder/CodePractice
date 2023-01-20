/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int bill : bills) {
            if (bill == 5)
                five++;
            else if (bill == 10) {
                five--;
                ten++;
                if (five < 0) return false;
            } else if (bill == 20) {
                if (ten && five) {
                    ten--;
                    five--;
                } else {
                    five -= 3;
                    if (five < 0) return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

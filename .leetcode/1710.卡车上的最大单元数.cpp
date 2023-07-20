/*
 * @lc app=leetcode.cn id=1710 lang=cpp
 *
 * [1710] 卡车上的最大单元数
 */

// @lc code=start
// 贪心
class Solution {
   public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });
        int res = 0;
        for (auto& x : boxTypes) {
            if (x[0] < truckSize) {
                res += x[0] * x[1];
                truckSize -= x[0];
            } else {
                res += truckSize * x[1];
                break;
            }
        }
        return res;
    }
};
// @lc code=end

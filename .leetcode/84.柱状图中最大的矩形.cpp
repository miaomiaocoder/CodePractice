/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        heights.insert(heights.begin(), 0);
        heights.emplace_back(0);
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i < heights.size(); ++i) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int mid = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    int w = i - stk.top() - 1;
                    int h = heights[mid];
                    res = max(res, h * w);
                }
            }
            stk.push(i);
        }
        return res;
    }
};
// @lc code=end

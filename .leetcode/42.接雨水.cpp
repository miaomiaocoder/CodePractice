/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        maxLeft[0] = height[0];
        for (int i = 1; i < height.size(); ++i) {
            maxLeft[i] = max(height[i], maxLeft[i - 1]);
        }
        maxRight[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; --i) {
            maxRight[i] = max(height[i], maxRight[i + 1]);
        }

        int sum = 0;
        for (int i = 0; i < height.size(); ++i) {
            int count = min(maxLeft[i], maxRight[i]) - height[i];
            if (count > 0) sum += count;
        }
        return sum;
    }
};

class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        stack<int> stk;
        stk.push(0);
        int sum = 0;
        for (int i = 1; i < height.size(); ++i) {
            if (height[i] < height[stk.top()]) {
                stk.push(i);
            } else if (height[i] == height[stk.top()]) {
                stk.pop();
                stk.push(i);
            } else {
                while (!stk.empty() && height[i] > height[stk.top()]) {
                    int mid = stk.top();
                    stk.pop();
                    if (!stk.empty()) {
                        int h = min(height[stk.top()], height[i]) - height[mid];
                        int w = i - stk.top() - 1;
                        sum += h * w;
                    }
                }
                stk.push(i);
            }
        }
        return sum;
    }
};

class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        stack<int> stk;
        stk.push(0);
        int sum = 0;
        for (int i = 1; i < height.size(); ++i) {
            while (!stk.empty() && height[i] >= height[stk.top()]) {
                int mid = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    int h = min(height[i], height[stk.top()]) - height[mid];
                    int w = i - stk.top() - 1;
                    sum += h * w;
                }
            }
            stk.push(i);
        }
        return sum;
    }
};
// @lc code=end

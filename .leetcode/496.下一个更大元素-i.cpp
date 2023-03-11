/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        vector<int> res(nums1.size(), -1);

        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); ++i) {
            umap[nums1[i]] = i;
        }
        stk.push(0);
        for (int i = 1; i < nums2.size(); ++i) {
            if (nums2[i] < nums2[stk.top()]) {
                stk.push(i);
            } else if (nums2[i] == nums2[stk.top()]) {
                stk.push(i);
            } else {
                while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
                    if (umap.count(nums2[stk.top()]) > 0) {
                        int idx = umap[nums2[stk.top()]];
                        res[idx] = nums2[i];
                    }
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return res;
    }
};

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        vector<int> res(nums1.size(), -1);
        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); ++i) {
            umap[nums1[i]] = i;
        }

        stk.push(0);
        for (int i = 1; i < nums2.size(); ++i) {
            while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
                if (umap.count(nums2[stk.top()]) > 0) {
                    int idx = umap[nums2[stk.top()]];
                    res[idx] = nums2[i];
                }
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};
// @lc code=end

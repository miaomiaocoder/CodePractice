// https://leetcode.cn/problems/missing-element-in-sorted-array/

class Solution {
   public:
    int missingElement(vector<int>& nums, int k) {
        int res = nums[0] - 1;
        for (int i = 0; i < nums.size(); i++) {
            while (res != nums[i] - 1) {
                res++;
                k--;
                if (k == 0) return res;
            }
            res = nums[i];
        }
        return res + k;
    }
};
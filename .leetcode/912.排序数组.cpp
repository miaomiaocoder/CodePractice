/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
// 快速排序
class Solution {
    void quikSort(vector<int>&nums, int l, int r) {
        if (l >= r) return;
        int x = nums[l + r >> 1], i = l - 1, j = r + 1;
        while (i < j) {
            do ++i; while (nums[i] < x);
            do --j; while (nums[j] > x);
            if (i < j) swap(nums[i], nums[j]);
        }
        quikSort(nums, l, j);
        quikSort(nums, j + 1, r);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quikSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

// 堆排序
class Solution {
    void maxHeapify(vector<int>& nums, int i, int n) {
        while (i * 2 + 1 < n) {
            int lson = i * 2 + 1;
            int rson = i * 2 + 2;
            int large = i;
            if (lson < n && nums[lson] > nums[i]) large = lson;
            if (rson < n && nums[rson] > nums[large]) large = rson;
            if (large != i) {
                swap(nums[i], nums[large]);
                i = large;
            } else
                break;
        }
    }
    void buildMaxHeap(vector<int>& nums) {
        int n = nums.size();
        for (int i = (n - 1) / 2; i >= 0; --i) {
            maxHeapify(nums, i, n);
        }
    }
    void heapSort(vector<int>& nums) {
        int n = nums.size();
        buildMaxHeap(nums);
        for (int i = n - 1; i >= 1; --i) {
            swap(nums[i], nums[0]);
            --n;
            maxHeapify(nums, 0, n);
        }
    }

   public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};

class Solution {
    void maxHeapify(vector<int>& nums, int i, int n) {
        int lson = i * 2 + 1;
        int rson = i * 2 + 2;
        int large = i;
        if (lson < n && nums[lson] > nums[i]) large = lson;
        if (rson < n && nums[rson] > nums[large]) large = rson;
        if (large != i) {
            swap(nums[i], nums[large]);
            maxHeapify(nums, large, n);
        }
    }
    void buildMaxHeap(vector<int>& nums) {
        int n = nums.size();
        for (int i = (n - 1) / 2; i >= 0; --i) {
            maxHeapify(nums, i, n);
        }
    }
    void heapSort(vector<int>& nums) {
        int n = nums.size();
        buildMaxHeap(nums);
        for (int i = n - 1; i >= 1; --i) {
            swap(nums[i], nums[0]);
            --n;
            maxHeapify(nums, 0, n);
        }
    }

   public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};
// @lc code=end

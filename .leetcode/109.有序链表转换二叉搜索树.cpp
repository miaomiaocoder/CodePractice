/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        int n = 0;
        for (ListNode* p = head; p; p = p->next) n++;
        if (n == 1) return new TreeNode(head->val);
        ListNode* cur = head;
        for (int i = 0; i < n / 2 - 1; i++)
            cur = cur->next;  // cur遍历到中点前一位，方便处理
        TreeNode* root = new TreeNode(cur->next->val);
        root->right = sortedListToBST(cur->next->next);
        cur->next = nullptr;
        root->left = sortedListToBST(head);
        return root;
    }
};

// 链表转换成数组
class Solution {
   public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        };
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        int mid = l + r >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, l, mid - 1);
        root->right = build(nums, mid + 1, r);
        return root;
    }
};
// @lc code=end

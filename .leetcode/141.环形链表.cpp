/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) return false;
        ListNode *slow = head, *fast = head;
        while (fast) {
            slow = slow->next, fast = fast->next;
            if (!fast) return false;
            fast = fast->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
// @lc code=end

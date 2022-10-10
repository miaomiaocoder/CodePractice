/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        ListNode *slow = head, *fast = head;
        while (fast) {
            slow = slow->next, fast = fast->next;
            if (!fast) return nullptr;
            fast = fast->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) slow = slow->next, fast = fast->next;
                return slow;
            }
        }
        return nullptr;
    }
};
// @lc code=end

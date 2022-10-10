/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
// 递归法
class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
};

// 迭代法
class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* a = head;
        ListNode* b = head->next;
        while (b) {
            ListNode* tmp = b->next;
            b->next = a;
            a = b;
            b = tmp;
        }
        head->next = nullptr;
        return a;
    }
};
// @lc code=end

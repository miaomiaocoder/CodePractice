/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
// 设立一个伪头节点问题容易解决
class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        for (ListNode* p = head; p; p = p->next) len++;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        for (int i = 0; i < len - n; i++) p = p->next;
        p->next = p->next->next;

        return dummy->next;
    }
};

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return nullptr;
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *fast = newHead, *slow = newHead;
        ListNode* pre = newHead;
        while (n--) {
            fast = fast->next;
        }
        while (fast) {
            pre = slow;
            fast = fast->next;
            slow = slow->next;
        }
        pre->next = pre->next->next;
        return newHead->next;
    }
};

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = 0;
        ListNode* cur = head;
        while (cur) {
            cur = cur->next;
            ++k;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        cur = dummy;
        int t = k - n;
        for (int i = 0; i < t; ++i) cur = cur->next;
        cur->next = cur->next->next;
        return dummy->next;
    }
};
// @lc code=end

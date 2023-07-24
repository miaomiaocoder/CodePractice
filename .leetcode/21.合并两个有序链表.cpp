/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* cur = new ListNode(-1);
        ListNode* dummy = cur;
        while (cur1 && cur2) {
            if (cur1->val > cur2->val) {
                cur->next = cur2;
                cur2 = cur2->next;
            } else {
                cur->next = cur1;
                cur1 = cur1->next;
            }
            cur = cur->next;
        }
        if (cur1) cur->next = cur1;
        if (cur2) cur->next = cur2;
        return dummy->next;
    }
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *cur1 = list1, *cur2 = list2;
        ListNode* cur = new ListNode(-1);
        ListNode* pre = cur;
        while (cur1 && cur2) {
            if (cur1->val > cur2->val)
                cur = cur->next = cur2, cur2 = cur2->next;
            else
                cur = cur->next = cur1, cur1 = cur1->next;
        }
        if (cur1) cur->next = cur1;
        if (cur2) cur->next = cur2;
        return pre->next;
    }
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
// @lc code=end

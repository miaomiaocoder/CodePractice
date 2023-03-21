/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        ListNode* cur = head;
        if (cur == nullptr) return;
        while (cur != nullptr) {
            vec.emplace_back(cur);
            cur = cur->next;
        }

        int i = 1;
        int j = vec.size() - 1;
        int count = 0;
        cur = head;
        while (i <= j) {
            if (count % 2 == 0) {
                cur->next = vec[j];
                --j;
            } else {
                cur->next = vec[i];
                ++i;
            }
            count++;
            cur = cur->next;
        }
        cur->next = nullptr;
    }
};
// @lc code=end

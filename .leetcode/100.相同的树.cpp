/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
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
// 递归法
class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (p && !q) return false;
        if (!p && q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q || p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// 迭代法，同时中序遍历
class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        stack<TreeNode*> pstk, qstk;
        while (p || q || pstk.size() || qstk.size()) {
            while (p && q) {
                pstk.push(p), qstk.push(q);
                p = p->left, q = q->left;
            }
            if (p || q) return false;
            p = pstk.top(), q = qstk.top();
            pstk.pop(), qstk.pop();
            if (p->val != q->val) return false;
            p = p->right, q = q->right;
        }
        return true;
    }
};
// @lc code=end

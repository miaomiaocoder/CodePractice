/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
// 树的哈希
class Solution {
   public:
    const int P = 131, Q = 151, MOD = 1e7 + 7;
    int T = -1;
    bool ans = false;

    int dfs(TreeNode* root) {
        if (!root) return 12345;
        int left = dfs(root->left), right = dfs(root->right);
        if (left == T || right == T) ans = true;
        return (left * P % MOD + right * Q % MOD + root->val) % MOD;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // T = dfs(subRoot);
        // if (T == dfs(root)) ans = true;
        // 上两行效果与下面一行等价
        if ((T = dfs(subRoot)) == dfs(root)) ans = true;
        return ans;
    }
};

// 递归
class Solution {
   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return !subRoot;
        return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q || p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
// @lc code=end

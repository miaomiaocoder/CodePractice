/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
// 递归结点u存在时候，u的左节点p的左子树和右节点q的右子树应该对称，p->right和q->left应该对称
class Solution {
   public:
    bool dfs(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q || p->val != q->val) return false;
        return dfs(p->left, q->right) && dfs(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return dfs(root->left, root->right);
    }
};

// 用栈模拟递归，对根节点的左子树，我们用中序遍历；对根节点的右子树，我们用反中序遍历。
// 则两个子树互为镜像，当且仅当同时遍历两课子树时，对应节点的值相等。
// 注意要同时遍历
class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> left, right;
        TreeNode* p = root->left;
        TreeNode* q = root->right;
        while (p || q || left.size() || right.size()) {
            while (p && q) {
                left.push(p), right.push(q);
                p = p->left, q = q->right;
            }
            if (p || q)
                return false;  // 同时遍历，如果有没有遍历完的，说明不对称
            p = left.top(), q = right.top();
            left.pop(), right.pop();
            if (p->val != q->val) return false;
            p = p->right, q = q->left;
        }
        return true;
    }
};
// @lc code=end

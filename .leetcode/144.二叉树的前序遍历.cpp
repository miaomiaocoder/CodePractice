/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
// 94中序 144前序 145后序
// 递归遍历
class Solution {
   public:
    vector<int> res;
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};

// 迭代遍历
class Solution {
   public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root || stk.size()) {
            while (root) {
                res.emplace_back(root->val);
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top()->right;
            stk.pop();
        }
        return res;
    }
};

class Solution {
   public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if (!root) return res;
        while (stk.size() || root) {
            while (root) {
                res.emplace_back(root->val);
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return res;
    }
};
// @lc code=end

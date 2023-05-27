/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
class Solution {
    vector<int> vec;

   public:
    void traversal(TreeNode* root) {
        if (!root) return;
        traversal(root->left);
        vec.emplace_back(root->val);
        traversal(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        traversal(root);
        return vec[k - 1];
    }
};

class Solution {
   public:
    int ans, k_;
    int kthSmallest(TreeNode* root, int k) {
        k_ = k;
        traversal(root);
        return ans;
    }

    bool traversal(TreeNode* root) {
        if (!root) return false;
        if (traversal(root->left)) return true;
        if (--k_ == 0) {
            ans = root->val;
            return true;
        }
        return traversal(root->right);
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
// 中序遍历
class Solution {
   public:
    long long last = LONG_MIN;  // 因为后台测试数据中有int最小值
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        bool left = isValidBST(root->left);
        // 中序遍历，验证遍历的元素是不是从小到大
        if (last < root->val)
            last = root->val;
        else
            return false;
        bool right = isValidBST(root->right);

        return left && right;
    }
};

// dfs
class Solution {
   public:
    bool isValidBST(TreeNode* root) { return dfs(root, LONG_MIN, LONG_MAX); }

    bool dfs(TreeNode* root, long left, long right) {
        if (!root) return true;
        if (root->val <= left || root->val >= right) return false;
        return dfs(root->left, left, root->val) &&
               dfs(root->right, root->val, right);
    }
};
// @lc code=end

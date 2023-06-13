/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
// 和leetcode104题目很像，只不过这个是要考虑加节点值（注意负数情况）
class Solution {
    int ans;

   public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* cur) {
        if (!cur) return 0;
        int left = max(0, dfs(cur->left)), right = max(0, dfs(cur->right));
        ans = max(ans, cur->val + left + right);
        return cur->val + max(left, right);
    }
};

class Solution {
    int res = INT_MIN;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};
// @lc code=end

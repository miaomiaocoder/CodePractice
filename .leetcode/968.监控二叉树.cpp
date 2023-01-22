/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
   private:
    const int INF = 1e8;
    //（1）f[0] 时，由于当前结点没有摄像头，子结点必须被其自身或者其子结点监控，因此取 min(l[1], l[2])
    //（2）f[1] 时，由于必有一个子结点有监控，则另个子结点可以有监控（被自己观察）也可以没监控（被其孩子观察），因此取 min(l[2] + min(r[1], r[2])
    //（3）f[2] 时，由于当前结点有摄像头，子结点可以处于三种状态中的任意一种，但是需要加上自身的摄像头，因此取 1 + min(l[0], min(l[1], l[2]))
    vector<int> dfs(TreeNode* root) {
        if (!root) return {0, 0, INF};
        auto l = dfs(root->left), r = dfs(root->right);
        return {
            min(l[1], l[2]) + min(r[1], r[2]),
            min(l[2] + min(r[1], r[2]), r[2] + min(l[1], l[2])),
            min(l[0], min(l[1], l[2])) + min(r[0], min(r[1], r[2])) + 1,
        };
    }

   public:
    // 状态表示 f 是长度为 3 的数组，其左右孩子结构相同，用 l 和 r 表示。
    // f[0] 表示当前结点被父结点监控的情况下，所需最少摄像头数；f[0] = min(l[1], l[2]) + min(r[1], r[2])。
    // f[1] 表示当前结点被子结点监控的情况下，所需最少摄像头数；f[1] = min(l[2] + min(r[1], r[2]), r[2] + min(l[1], l[2]))。
    // f[2] 表示当前结点被自己监控的情况下，所需最少摄像头数；f[2] = 1 + min(l[0], min(l[1], l[2])) + min(r[0], min(r[1], r[2]))。
    int minCameraCover(TreeNode* root) {
        auto f = dfs(root);
        return min(f[1], f[2]);
    }
};
// @lc code=end

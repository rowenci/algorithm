/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getDepth(TreeNode* node){
        // 节点为空，返回为空（可能是子树为空，或根节点为空）
        if(node == nullptr) return 0;
        // 判断左子树是否平衡
        int leftDepth = getDepth(node->left);
        if(leftDepth == -1) return -1;
        // 判断右子树是否平衡
        int rightDepth = getDepth(node->right);
        if(rightDepth == -1) return -1;
        // 终止条件为：左右子树是否平衡，并返回当前节点的总高度
        return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + max(leftDepth, rightDepth);
    }
    bool isBalanced(TreeNode* root) {
        return getDepth(root) == -1 ? false : true;
    }
};
// @lc code=end


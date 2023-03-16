/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode* inorder(TreeNode* node, int val){
        if(node == nullptr){
            TreeNode* tn = new TreeNode(val);
            return tn;
        }
        if(node->val > val)
            node->left = inorder(node->left, val);
        if(node->val < val)
            node->right = inorder(node->right, val);
        return node;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        inorder(root, val);
        return root;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int minValue = __INT_MAX__;
    TreeNode* preNode = nullptr;

    void inorder(TreeNode* node){
        if(node == nullptr)
            return;
        inorder(node->left);
        if(preNode != nullptr)
            // 因为有序，所以直接减然后比大小就行
            minValue = min(minValue, node->val - preNode->val);
        preNode = node;
        inorder(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minValue;
    }
};
// @lc code=end


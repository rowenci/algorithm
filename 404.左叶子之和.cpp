/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    void getLeftLeaf(TreeNode* node, bool isLeft, int& res){
        if(node->left == nullptr && node->right == nullptr && isLeft) res += node->val;
        if(node->left != nullptr) getLeftLeaf(node->left, true, res);
        if(node->right != nullptr) getLeftLeaf(node->right, false, res);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        int res = 0;
        getLeftLeaf(root, false, res);
        return res;
    }
};
// @lc code=end


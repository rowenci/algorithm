/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool deepOrder(TreeNode* node, int targetSum, int sum){
        sum += node->val;
        if(node->left == nullptr && node->right == nullptr){
            if(sum == targetSum)
                return true;
            else
                return false;
        }
        
        bool leftFlag, rightFlag;
        if(node->left != nullptr)
            leftFlag = deepOrder(node->left, targetSum, sum);
        if(node->right != nullptr)
            rightFlag = deepOrder(node->right, targetSum, sum);
        return leftFlag || rightFlag;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return false;
        if(root->left == nullptr && root->right == nullptr && root->val != targetSum)
            return false;
        int sum = 0;
        return deepOrder(root, targetSum, sum);
    }
};
// @lc code=end


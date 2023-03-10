/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaxTree(vector<int>& nums, int left, int right){
        // 子树为空
        if(left >= right)
            return nullptr;
        
        // 找到最大值作为根节点
        int maxValueIndex = left;
        for(int i = left + 1; i < right; i++)
            if(nums[i] > nums[maxValueIndex])
                maxValueIndex = i;
        
        TreeNode* root = new TreeNode(nums[maxValueIndex]);

        // 递归生成左子树
        root->left = constructMaxTree(nums, left, maxValueIndex);
        // 递归生成右子树
        root->right = constructMaxTree(nums, maxValueIndex + 1, right);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;

        return constructMaxTree(nums, 0, nums.size());
    }
};
// @lc code=end


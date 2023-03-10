/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* travelsal(vector<int>& inorder, vector<int>& postorder){
        if(inorder.size() == 0)
            return nullptr;
        
        // find root node
        TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);

        if(inorder.size() == 1)
            return root;

        // find cut point
        int i = 0;
        for(; i < inorder.size(); i++){
            if(inorder[i] == root->val)
                break;
        }

        // cut inorder
        vector<int> leftInOrder(inorder.begin(), inorder.begin() + i);
        vector<int> rightInOrder(inorder.begin() + i + 1, inorder.end());

        // cut postorder
        postorder.resize(postorder.size() - 1);
        vector<int> leftPostOrder(postorder.begin(), postorder.begin() + leftInOrder.size());
        vector<int> rightPostOrder(postorder.begin() + leftInOrder.size(), postorder.end());

        root->left = travelsal(leftInOrder, leftPostOrder);
        root->right = travelsal(rightInOrder, rightPostOrder);

        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0)
            return nullptr;
        return travelsal(inorder, postorder);
    }
};
// @lc code=end


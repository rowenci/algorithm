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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* preNode = nullptr;

    // 使用中序遍历
    // 记录上一个遍历的节点
    // 因为中序遍历二叉搜索树结果是递增的，因此如果上一个节点的值比下一个节点的值大，就说明有错误
    // 二叉搜索树里面不存在相同值的节点
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        bool left = isValidBST(root->left);
        if(preNode != nullptr && preNode->val >= root->val)
            return false;
        preNode = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
};
// @lc code=end


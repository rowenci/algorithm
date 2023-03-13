/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        if(root == nullptr)
            return root->val;
        queue<TreeNode*> que;
        que.push(root);

        TreeNode* curNode;
        while(!que.empty()){
            curNode = que.front();
            que.pop();

            // 先入右子树，这样的话最后一个遍历的节点一定是最后一层、最左边的节点
            if(curNode->right != nullptr)
                que.push(curNode->right);
            if(curNode->left != nullptr)
                que.push(curNode->left);
        }
        return curNode->val;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int maxCount = 0;
    int count = 0;
    TreeNode* preNode = nullptr;
    vector<int> res;
    void inorder(TreeNode* curNode){
        if(curNode == nullptr)
            return;
        

        inorder(curNode->left); // 左


        // 中
        if(preNode == nullptr)  // 第一个遍历的节点，count直接为1
            count = 1;
        else if(preNode->val == curNode->val)   // 上一个节点值与当前节点值相同，count+1
            count++;
        else    // 上一个节点值与当前节点值不同，count变为1
            count = 1;
        preNode = curNode;  // 更新preNode
        if(count == maxCount)   // 如果是最大的数
            res.push_back(curNode->val);    // 放入结果集
        if(count > maxCount){   // 新的更大的众数
            maxCount = count;   // 记录下来
            res.clear();    // 清空上次记录众数的结果集
            res.push_back(curNode->val);    // 放入结果集
        }


        // 右
        inorder(curNode->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
};
// @lc code=end


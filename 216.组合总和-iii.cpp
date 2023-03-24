/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<int> item;
    vector<vector<int>> res;
    void backTrace(int k, int n, int startNumber){
        if(item.size() == k){
            res.push_back(item);
            return;
        }
        for(int i = startNumber; i <= 9; i++){

        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backTrace(k, n, 1);
        return res;
    }
};
// @lc code=end


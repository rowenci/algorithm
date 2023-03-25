/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> item;
    void backTrace(int k, int n, int sum, int startNumber){
        if(sum > n)
            return;
        if(item.size() == k){
            if (sum == n) 
                res.push_back(item);
            return;
        }
        for(int i = startNumber; i <= 9 - (k - item.size()) + 1; i++){
            sum += i;
            item.push_back(i);
            backTrace(k, n, sum, i + 1);
            sum -= i;
            item.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backTrace(k, n, 0, 1);
        return res;
    }
};
// @lc code=end


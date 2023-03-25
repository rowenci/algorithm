/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> item;
    void backTrace(vector<int>& candidates, int target, int sum, int startIndex){
        if(sum > target)
            return;
        if(sum == target){
            res.push_back(item);
            return;
        }

        for(int i = startIndex; i < candidates.size(); i++){
            sum += candidates[i];
            item.push_back(candidates[i]);
            backTrace(candidates, target, sum, i);  // 因为元素可以重复来，所以i不用+1
            sum -= candidates[i];
            item.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTrace(candidates, target, 0, 0);
        return res;
    }
};
// @lc code=end


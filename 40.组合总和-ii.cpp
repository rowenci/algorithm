/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
            // 同一层当中遇到相同的元素就跳过
            if(i > startIndex && candidates[i] == candidates[i - 1])
                continue;
            sum += candidates[i];
            item.push_back(candidates[i]);
            backTrace(candidates, target, sum, i + 1);  // 因为元素可以重复来，所以i不用+1
            sum -= candidates[i];
            item.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 先排序
        sort(candidates.begin(), candidates.end());
        backTrace(candidates, target, 0, 0);
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
public:
    vector<int> item;
    vector<vector<int>> res;
    void backTrace(vector<int>& nums, int startIndex){
        if(item.size() >= 2)
            res.push_back(item);

        int used[201] = {0};
        for(int i = startIndex; i < nums.size(); i++){
            if((!item.empty() && item.back() > nums[i]) || used[nums[i] + 100] == 1)
                continue;
            used[nums[i] + 100] = 1;
            item.push_back(nums[i]);
            backTrace(nums, i + 1);
            item.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backTrace(nums, 0);
        return res;
    }
};
// @lc code=end

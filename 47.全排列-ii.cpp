/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<int> item;
    vector<vector<int>> res;
    void backTrace(vector<int>& nums, vector<bool> used){
        if(item.size() == nums.size()){
            res.push_back(item);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            if(used[i] == false){
                used[i] = true;
                item.push_back(nums[i]);
                backTrace(nums, used);
                item.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backTrace(nums, used);
        return res;
    }
};
// @lc code=end


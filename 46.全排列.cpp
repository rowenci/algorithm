/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<int> item;
    vector<vector<int>> res;
    void backTrace(vector<int>& nums, vector<bool>& used){
        if(item.size() == nums.size()){
            res.push_back(item);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true)
                continue;
            used[i] = true;
            item.push_back(nums[i]);
            backTrace(nums, used);
            item.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backTrace(nums, used);
        return res;
    }
};
// @lc code=end


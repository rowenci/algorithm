/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
/*
递归函数的返回值以及参数
回溯函数终止条件
单层搜索的过程
*/
class Solution {
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int n, int k, int startIndex){
        if(path.size() == k){
            res.push_back(path);
            return;
        }
        // for(int i = startIndex; i <= n; i++){
        for(int i = startIndex; i <= n - (k - path.size()) + 1; i++){
            path.push_back(i);  // 处理节点
            backtracking(n, k, i + 1);  // 递归
            path.pop_back();    // 回溯，撤销处理的节点
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }
};
// @lc code=end


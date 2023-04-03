/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int num = 0;
        int index = s.size() - 1;
        for(int i = g.size() - 1; i >= 0; i--){
            // 因为饼干每个只能用一次，所以没法使用for循环来遍历。
            // 只能用index在for外面来表示饼干已经用过
            if(index >= 0 && s[index] >= g[i]){
                num++;
                index--;
            }
        }
        return num;
    }
};
// @lc code=end


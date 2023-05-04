/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    /*
    这道题考察的是不同区间是否有交集
    */
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), cmp);

        int arrowCount = 1;
        for(int i = 1; i < points.size(); i++){
            // 从左往右射
            if(points[i][0] > points[i - 1][1]) // i与i - 1不挨着
                arrowCount++;   // 多射一支箭
            else
                points[i][1] = min(points[i - 1][1], points[i][1]); // 将两个气球的边界更新
        }
        return arrowCount;
    }
};
// @lc code=end


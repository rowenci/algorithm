/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    void backTrace(const string& s, int startIndex, int pointNum){
        if(pointNum == 3){
            if(isValid(s, startIndex, s.size() - 1))
                res.push_back(s);
            return;
        }

        for(int i = startIndex; i < s.size(); i++){
            if(isValid(s, startIndex, i)){
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backTrace(s, i + 2, pointNum);
                pointNum--;
                s.erase(s.begin() + i + 1);
            }else
                break;
        }
    }
    bool isValid(const string& s, int startIndex, int endIndex){
        if(startIndex > endIndex)
            return false;
        if(s[startIndex] == '0' && start != end)
            return false;
        int num = 0;
        for(int i = startIndex; i <= endIndex; i++){
            if(s[i] > '9' || s[i] < '0')
                return false;
            num = num * 10 + (s[i] - '0');
            if(num > 255)
                return false;
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12)
            return res;
        backTrace(s, 0, 0);
        return res;
    }
};
// @lc code=end


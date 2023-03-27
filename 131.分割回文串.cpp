/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    /*
        切割字符的操作和组合的操作一样
    */
    vector<string> item;
    vector<vector<string>> res;
    void backTrace(const string& s, int startIndex){
        if(startIndex >= s.size()){
            res.push_back(item);
            return;
        }

        for(int i = startIndex; i < s.size(); i++){
            if(isPalindrome(s, startIndex, i)){
                string str = s.substr(startIndex, i - startIndex + 1);
                item.push_back(str);
            }else{
                continue;
            }
            backTrace(s, i + 1);
            item.pop_back();
        }
    }

    bool isPalindrome(const string& s, int startIndex, int endIndex){
        for(int i = startIndex, j = endIndex; i < j; i++, j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
    vector<vector<string>> partition(string s) {
        backTrace(s, 0);
        return res;
    }
};
// @lc code=end

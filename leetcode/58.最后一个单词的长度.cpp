/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res=0,i=s.length()-1;
        while(i>=0&&s[i]==' '){
            --i;
        }
        while(i>=0&&s[i]!=' '){
            --i;
            ++res;
        }
        return res;
    }
};
// @lc code=end


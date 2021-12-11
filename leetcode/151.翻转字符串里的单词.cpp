/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        bool firstWord=true;
        int start=-1,end=-1;
        string res;
        for(int i=0;i<s.size();++i){
            if(s[i]==' '){
                continue;
            }
            start=i;
            int ind=i+1;
            while(ind<s.size()&&s[ind]!=' '){
                ++ind;
            }
            if(!firstWord){
                res+=' ';
            }
            for(int j=ind-1;j>=start;--j){
                res+=s[j];
            }
            firstWord=false;
            i=ind;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end


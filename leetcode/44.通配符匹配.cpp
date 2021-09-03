/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[2][p.length()+1];
        dp[0][0]=true;
        bool inival=true;
        for(int j=0;j<p.length();++j){
            if(p[j]!='*'){
                inival=false;
            }
            dp[0][j+1]=inival;
        }
        for(int i=0;i<s.length();++i){
            dp[(i+1)%2][0]=false;
            for(int j=0;j<p.length();++j){
                if(p[j]=='?'){
                    dp[(i+1)%2][j+1]=dp[i%2][j];
                }else if(p[j]=='*'){
                    dp[(i+1)%2][j+1]=dp[(i+1)%2][j]|dp[i%2][j+1];
                }else if(s[i]==p[j]){
                    dp[(i+1)%2][j+1]=dp[i%2][j];
                }else{
                    dp[(i+1)%2][j+1]=false;
                }
            }
        }
        return dp[s.length()%2][p.length()];
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
// @lc code=start
class Solution {
public:
    bool dp[2020][2020];
    int f[2020];
    int minCut(string s) {
        memset(dp,1,sizeof(dp));
        for(int i=1;i<s.size();++i){
            for(int j=0;(j+i)<s.size();++j){
                dp[j][j+i]=(s[j]==s[j+i])&&dp[j+1][j+i-1];
            }
        }
        memset(f,0x3f,sizeof(f));
        for(int i=0;i<s.size();++i){
            if(dp[0][i]){
                f[i]=0;
            }else{
                for(int j=0;j<i;++j){
                    if(dp[j+1][i]){
                        f[i]=min(f[i],f[j]+1);
                    }
                }
            }
        }
        return f[s.size()-1];
    }
};
// @lc code=end


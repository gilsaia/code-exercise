/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */
#include<cstring>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.size()+s2.size())!=s3.size()){
            return false;
        }
        bool dp[2][220];
        memset(dp,0,sizeof(dp));
        bool hastrue;
        dp[0][0]=true;
        for(int i=1;i<=s3.size();++i){
            hastrue=false;
            for(int j=0;j<i;++j){
                if(dp[(i-1)%2][j]){
                    hastrue=true;
                    if(s3[i-1]==s1[j]){
                        dp[i%2][j+1]=true;
                    }
                    if(s3[i-1]==s2[i-1-j]){
                        dp[i%2][j]=true;
                    }
                    dp[(i-1)%2][j]=false;
                }
            }
            if(!hastrue){
                return false;
            }
        }
        for(int i=0;i<=s3.size();++i){
            if(dp[s3.size()%2][i]){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */
#include<string>
#include<cstring>
using namespace std;
// @lc code=start
class Solution {
public:
    unsigned long long dp[2][1020];
    int numDistinct(string s, string t) {
        if(s.size()<t.size()){
            return 0;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1,dp[1][0]=1;
        for(int i=0;i<s.size();++i){
            for(int j=0;j<t.size();++j){
                if(s[i]==t[j]){
                    dp[(i+1)%2][j+1]=dp[i%2][j]+dp[i%2][j+1];
                }else{
                    dp[(i+1)%2][j+1]=dp[i%2][j+1];
                }
            }
        }
        return dp[s.size()%2][t.size()];
    }
};
// @lc code=end


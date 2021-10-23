/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */
#include<string>
#include<cstring>
using namespace std;
// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0'){
            return 0;
        }
        int dp[120];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<s.size();++i){
            if(s[i-1]!='0'){
                int tmp=(s[i-1]-'0')*10+(s[i]-'0');
                if(tmp>0&&tmp<=26){
                    if((i-2)>=0){
                        dp[i]+=dp[i-2];
                    }else{
                        dp[i]+=1;
                    }
                }
            }
            if(s[i]!='0'){
                dp[i]+=dp[i-1];
            }
        }
        return dp[s.size()-1];
    }
};
// @lc code=end


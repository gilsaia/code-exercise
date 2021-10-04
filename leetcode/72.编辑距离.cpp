/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.length()==0||word2.length()==0){
            return max(word1.length(),word2.length());
        }
        vector<vector<int>> dp(2,vector<int>(word2.length()+1,0));
        for(int i=1;i<=word2.length();++i){
            dp[0][i]=dp[0][i-1]+1;
        }
        for(int i=1;i<=word1.length();++i){
            dp[i%2][0]=dp[(i+1)%2][0]+1;
            for(int j=1;j<=word2.length();++j){
                dp[i%2][j]=min(dp[i%2][j-1]+1,dp[(i+1)%2][j]+1);
                if(word1[i-1]==word2[j-1]){
                    dp[i%2][j]=min(dp[i%2][j],dp[(i+1)%2][j-1]);
                }else{
                    dp[i%2][j]=min(dp[i%2][j],dp[(i+1)%2][j-1]+1);
                }
            }
        }
        return dp[word1.length()%2][word2.length()];
    }
};
// @lc code=end


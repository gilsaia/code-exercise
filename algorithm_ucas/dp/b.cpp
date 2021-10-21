#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long dp[2];
int main(){
    long long cur;
    scanf("%lld",&cur);
    dp[0]=cur,dp[1]=0;
    while(~scanf("%lld",&cur)){
        dp[0]=max(dp[0],dp[1]+cur);
        dp[1]=max(dp[1],dp[0]-cur);
    }
    printf("%lld\n",dp[0]);
    return 0;
}
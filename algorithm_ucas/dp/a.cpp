#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[220][220];
int main(){
    int hei;
    scanf("%d",&hei);
    memset(dp,0x3f,sizeof(dp));
    int num=1;
    dp[0][0]=0;
    for(int i=0;i<hei;++i){
        int cur;
        for(int j=0;j<num;++j){
            scanf("%d",&cur);
            dp[i+1][j]=min(dp[i][j]+cur,dp[i+1][j]);
            dp[i+1][j+1]=min(dp[i][j]+cur,dp[i+1][j+1]);
        }
        ++num;
    }
    int ans=0x3f3f3f3f;
    for(int i=0;i<=num;++i){
        ans=min(ans,dp[hei][i]);
    }
    printf("%d\n",ans);
    return 0;
}
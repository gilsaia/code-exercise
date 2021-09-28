#include<cstdio>
#include<algorithm>
using namespace std;
int dat[100020];
int n,m;
void find(int &target){
    int l=0,r=n;
    int resl=-1,resr=-1;
    while(l<r){
        int m=(l+r)/2;
        if(dat[m]>=target){
            r=m;
        }else if(dat[m]<target){
            l=m+1;
        }
    }
    if(dat[l]!=target){
        printf("-1 -1\n");
        return;
    }
    resl=l;
    l=0,r=n;
    while(l<r){
        int m=(l+r)/2;
        if(dat[m]>target){
            r=m;
        }else if(dat[m]<=target){
            l=m+1;
        }
    }
    resr=l-1;
    printf("%d %d\n",resl,resr);
    return;
}
 
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",&dat[i]);
    }
    int target;
    for(int i=0;i<m;++i){
        scanf("%d",&target);
        find(target);
    }
    return 0;
}
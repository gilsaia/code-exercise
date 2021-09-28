#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
const long long MOD=1337;
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

long long modpow(long long a,vector<int> &b){
    long long res=1;
    if(b.size()==1&&b[0]==0){
        return res;
    }
    while(!(b.size()==1&&b[0]==0)){
        int r=b[0]&1;
        if(r){
            res=(res*a)%MOD;
        }
        a=(a*a)%MOD;
        b=div(b,2,r);
    }
    return res;
}

int main(){
    long long a;
    cin>>a;
    a%=MOD;
    vector<int> b;
    string strb;
    cin>>strb;
    istringstream is(strb);
    while(true){
        char tmp;
        is>>tmp;
        if(tmp==']'){
            break;
        }else if(tmp<='9'&&tmp>='0'){
            b.push_back(tmp-'0');
        }
    }
    reverse(b.begin(),b.end());
    long long res=modpow(a,b);
    cout<<res<<endl;
    return 0;
}
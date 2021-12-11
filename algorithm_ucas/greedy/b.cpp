#include<string>
#include<vector>
#include<iostream>
using namespace std;
int count[30];
int main(){
    string s;
    vector<int> res;
    cin>>s;
    for(int i=0;i<s.size();++i){
        count[s[i]-'a']=i;
    }
    int left=0;
    while(left<s.size()){
        for(int i=left;i<=left;++i){
            left=max(left,count[s[i]-'a']);
        }
        res.push_back(left);
        ++left;
    }
    cout<<res[0]+1;
    for(int i=1;i<res.size();++i){
        cout<<" "<<res[i]-res[i-1];
    }
    cout<<endl;
    return 0;
}
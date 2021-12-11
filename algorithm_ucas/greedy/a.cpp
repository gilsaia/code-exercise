#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int left=0,right=0;
    bool res=true;
    for(char &c:s){
        if(c=='('){
            ++left;
            ++right;
        }else if(c==')'){
            if(left>0){
                --left;
            }
            if(right>0){
                --right;
            }else{
                res=false;
                break;
            }
        }else{
            if(left>0){
                --left;
            }
            ++right;
        }
    }
    if(left!=0){
        res=false;
    }
    if(res){
        cout<<"True"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
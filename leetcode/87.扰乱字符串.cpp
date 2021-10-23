/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
    int memory[32][32][32];
public:
    bool check(string &s1,string &s2,int &i1,int &i2,int &length){
        unordered_map<char,int> fin;
        for(int i=0;i<length;++i){
            ++fin[s1[i+i1]];
        }
        for(int i=0;i<length;++i){
            --fin[s2[i+i2]];
        }
        for(auto iter:fin){
            if(iter.second!=0){
                return false;
            }
        }
        return true;
    }
    bool dfs(string &s1,string &s2,int i1,int i2,int length){
        if(memory[i1][i2][length]==1){
            return true;
        }else if(memory[i1][i2][length]==0){
            return false;
        }
        if(s1.substr(i1,length)==s2.substr(i2,length)){
            memory[i1][i2][length]=1;
            return true;
        }
        if(!check(s1,s2,i1,i2,length)){
            memory[i1][i2][length]=0;
            return false;
        }
        for(int i=1;i<length;++i){
            if(dfs(s1,s2,i1,i2,i)&&dfs(s1,s2,i1+i,i2+i,length-i)){
                memory[i1][i2][length]=1;
                return true;
            }
            if(dfs(s1,s2,i1,i2+length-i,i)&&dfs(s1,s2,i1+i,i2,length-i)){
                memory[i1][i2][length]=1;
                return true;
            }
        }
        memory[i1][i2][length]=0;
        return false;
    }
    bool isScramble(string s1, string s2) {
        memset(memory,0xff,sizeof(memory));
        return dfs(s1,s2,0,0,s1.length());
    }
};
// @lc code=end


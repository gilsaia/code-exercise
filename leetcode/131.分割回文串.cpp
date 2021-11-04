/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool check(string &s,int index,int len){
        int l=index,r=index+len-1;
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            ++l,--r;
        }
        return true;
    }
    void dfs(vector<vector<string>> &res,vector<string> &ans,string &s,int index){
        if(index==s.size()){
            res.push_back(ans);
            return;
        }
        for(int i=1;i<=(s.size()-index);++i){
            if(check(s,index,i)){
                ans.push_back(s.substr(index,i));
                dfs(res,ans,s,index+i);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        dfs(res,ans,s,0);
        return res;
    }
};
// @lc code=end


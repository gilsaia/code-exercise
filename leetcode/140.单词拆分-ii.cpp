/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    unordered_map<int,vector<string>> ans;
    unordered_set<string> hash;
    void dfs(const string &s,int index){
        if(!ans.count(index)){
            if(index==s.size()){
                ans[index]={""};
                return;
            }
            ans[index]={};
            for(int i=index+1;i<=s.size();++i){
                string word=s.substr(index,i-index);
                if(hash.count(word)){
                    dfs(s,i);
                    for(const string &succ:ans[i]){
                        ans[index].push_back(succ.empty()?word:word+" "+succ);
                    }
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string &s:wordDict){
            hash.insert(s);
        }
        dfs(s,0);
        return ans[0];
    }
};
// @lc code=end


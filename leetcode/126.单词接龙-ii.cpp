/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> path[5020];
    vector<int> startpath;
    int endpos;
    int priority[5020];
    bool checkstr(string &a,string &b){
        int count=0;
        for(int i=0;i<a.size();++i){
            if(a[i]!=b[i]){
                ++count;
                if(count>1){
                    return false;
                }
            }
        }
        return count==1;
    }
    void dfs(vector<vector<string>> &res,vector<string> &ans,vector<string> &wordList,set<int> &used,int &start){
        ans.push_back(wordList[start]);
        used.insert(start);
        if(start==endpos){
            res.push_back(ans);
            ans.pop_back();
            used.erase(start);
            return;
        }
        for(int i:path[start]){
            if(used.find(i)!=used.end()||priority[i]>=priority[start]){
                continue;
            }
            dfs(res,ans,wordList,used,i);
        }
        ans.pop_back();
        used.erase(start);
        return;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        endpos=-1;
        for(int i=0;i<wordList.size();++i){
            if(wordList[i]==endWord){
                endpos=i;
                break;
            }
        }
        if(endpos==-1){
            return res;
        }
        for(int i=0;i<wordList.size();++i){
            for(int j=0;j<i;++j){
                if(checkstr(wordList[i],wordList[j])){
                    path[i].push_back(j);
                    path[j].push_back(i);
                }
            }
            if(checkstr(wordList[i],beginWord)){
                startpath.push_back(i);
            }
        }
        memset(priority,0,sizeof(priority));
        priority[endpos]=1;
        queue<int> que;
        que.push(endpos);
        while(!que.empty()){
            int cur=que.front();
            que.pop();
            for(int i:path[cur]){
                if(priority[i]!=0){
                    continue;
                }
                priority[i]=priority[cur]+1;
                que.push(i);
            }
        }
        int startmax=5020;
        for(int i:startpath){
            startmax=min(startmax,priority[i]);
        }
        vector<string> ans;
        ans.push_back(beginWord);
        set<int> used;
        for(int i:startpath){
            if(priority[i]>startmax){
                continue;
            }
            dfs(res,ans,wordList,used,i);
        }
        return res;
    }
};
// @lc code=end


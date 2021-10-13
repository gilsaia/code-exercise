/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    bool vis[6][6];
    bool dfs(vector<vector<char>> &board,int x,int y,int k,string &word,int &m,int &n){
        if(board[x][y]!=word[k]){
            return false;
        }
        if(word.length()==(k+1)){
            return true;
        }
        vis[x][y]=true;
        for(int i=0;i<4;++i){
            if((x+dx[i])<m&&(y+dy[i])<n&&(x+dx[i])>=0&&(y+dy[i])>=0&&!vis[x+dx[i]][y+dy[i]]){
                if(dfs(board,x+dx[i],y+dy[i],k+1,word,m,n)){
                    return true;
                }
            }
        }
        vis[x][y]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(dfs(board,i,j,0,word,m,n)){
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end


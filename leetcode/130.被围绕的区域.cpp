/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    void dfs(vector<vector<char>> &board,int x,int y){
        board[x][y]='Z';
        for(int i=0;i<4;++i){
            int tx=x+dx[i],ty=y+dy[i];
            if(tx>=0&&tx<board.size()&&ty>=0&&ty<board[0].size()){
                if(board[tx][ty]=='O'){
                    dfs(board,tx,ty);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<n;++i){
            if(board[0][i]=='O'){
                dfs(board,0,i);
            }
            if(board[m-1][i]=='O'){
                dfs(board,m-1,i);
            }
        }
        for(int i=0;i<board.size();++i){
            if(board[i][0]=='O'){
                dfs(board,i,0);
            }
            if(board[i][n-1]=='O'){
                dfs(board,i,n-1);
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='Z'){
                    board[i][j]='O';
                }
            }
        }
    }
};
// @lc code=end


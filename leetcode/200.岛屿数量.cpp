/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    void dfs(vector<vector<int>> &map,vector<vector<char>> &grid,int x,int y,int &m,int &n){
        for(int i=0;i<4;++i){
            int tx=x+dx[i],ty=y+dy[i];
            if(tx<0||tx>=m||ty<0||ty>=n){
                continue;
            }
            if(!map[tx][ty]){
                map[tx][ty]=1;
                if(grid[tx][ty]=='1'){
                    dfs(map,grid,tx,ty,m,n);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        vector<vector<int>> map(grid.size(),vector<int>(grid[0].size(),0));
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(!map[i][j]){
                    map[i][j]=1;
                    if(grid[i][j]=='1'){
                        ++res;
                        dfs(map,grid,i,j,m,n);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end


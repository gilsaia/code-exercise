/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    void find(vector<string>& table,vector<vector<string>>& ans,int row,int& n,vector<int>& queens){
        for(int i=0;i<n;++i){
            int x=row,y=i;
            bool check=true;
            for(int j=0;j<row;++j){
                int tx=j,ty=queens[j];
                if(ty==y||((tx-x)==(ty-y))||((x-tx)==(ty-y))){
                    check=false;
                    break;
                }
            }
            if(check){
                table[row][i]='Q';
                if(row==(n-1)){
                    ans.push_back(table);
                    table[row][i]='.';
                    return;
                }
                queens.push_back(i);
                find(table,ans,row+1,n,queens);
                queens.pop_back();
                table[row][i]='.';
            }
        }
        return;
    } 
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> table(n,string(n,'.'));
        vector<int> queens;
        find(table,ans,0,n,queens);
        return ans;
    }
};
// @lc code=end


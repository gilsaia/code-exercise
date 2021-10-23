/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */
#include<vector>
#include<stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0){
            return 0;
        }
        stack<int> sta;
        sta.push(-1);
        int ans=0;
        vector<int> dat(matrix[0].size(),0);
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(matrix[i][j]=='1'){
                    dat[j]++;
                }else{
                    dat[j]=0;
                }
                while(sta.top()!=-1&&dat[sta.top()]>=dat[j]){
                    int hei=dat[sta.top()];
                    sta.pop();
                    int left=sta.top()+1,right=j;
                    ans=max(ans,(right-left)*hei);
                }
                sta.push(j);
            }
            while(sta.top()!=-1){
                int hei=dat[sta.top()];
                sta.pop();
                int left=sta.top()+1,right=matrix[0].size();
                ans=max(ans,(right-left)*hei);
            }
        }
        return ans;
    }
};
// @lc code=end


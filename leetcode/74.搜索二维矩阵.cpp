/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,r=matrix.size();
        while((r-l)>1){
            int m=(l+r)/2;
            if(matrix[m][0]>target){
                r=m;
            }else if(matrix[m][0]<target){
                l=m;
            }else{
                return true;
            }
        }
        if(matrix[l][0]>target){
            return false;
        }
        int ind=l;
        l=0,r=matrix[0].size();
        while(l<r){
            int m=(l+r)/2;
            if(matrix[ind][m]<target){
                l=m+1;
            }else if(matrix[ind][m]>target){
                r=m;
            }else{
                return true;
            }
        }
        return false;
    }
};
// @lc code=end


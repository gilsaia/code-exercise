/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int start=0,len=matrix.size();
        while(start<(len/2)){
            for(int i=0;i<(len-1-2*start);++i){
                swap(matrix[start][start+i],matrix[start+i][len-1-start]);
                swap(matrix[start][start+i],matrix[len-1-start-i][start]);
                swap(matrix[len-1-start-i][start],matrix[len-1-start][len-1-start-i]);
            }
            ++start;
        }
        return;
    }
};
// @lc code=end


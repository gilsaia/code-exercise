/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int rows = n, columns = n;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        int cur=1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                res[top][column]=cur;
                ++cur;
            }
            for (int row = top + 1; row <= bottom; row++) {
                res[row][right]=cur;
                ++cur;
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    res[bottom][column]=cur;
                    ++cur;
                }
                for (int row = bottom; row > top; row--) {
                    res[row][left]=cur;
                    ++cur;
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
    }
};
// @lc code=end


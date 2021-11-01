/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(1,1);
        for(int i=0;i<rowIndex;++i){
            int tmp=ans[0];
            for(int j=0;(j+1)<ans.size();++j){
                int newtmp=tmp+ans[j+1];
                tmp=ans[j+1];
                ans[j+1]=newtmp;
            }
            ans.push_back(1);
        }
        return ans;
    }
};
// @lc code=end


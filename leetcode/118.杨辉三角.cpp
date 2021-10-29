/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> ans(1,1);
        res.push_back(ans);
        for(int i=1;i<numRows;++i){
            int tmp=ans[0];
            for(int j=0;(j+1)<ans.size();++j){
                int newtmp=tmp+ans[j+1];
                tmp=ans[j+1];
                ans[j+1]=newtmp;
            }
            ans.push_back(1);
            res.push_back(ans);
        }
        return res;
    }
};
// @lc code=end


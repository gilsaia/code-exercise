/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        int l=intervals[0][0],r=intervals[0][1];
        for(vector<int> &interval:intervals){
            if(interval[0]>r){
                res.push_back(vector<int>{l,r});
                l=interval[0],r=interval[1];
            }else{
                r=max(r,interval[1]);
            }
        }
        res.push_back(vector<int>{l,r});
        return res;
    }
};
// @lc code=end


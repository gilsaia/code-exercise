/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */
#include<algorithm>
#include<vector>
using namespace std;
// @lc code=start
class Solution2 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int num=lower_bound(intervals.begin(),intervals.end(),newInterval)-intervals.begin();
        intervals.insert(intervals.begin()+num,newInterval);
        vector<vector<int>> res;
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
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        //分为三部分：
        //1.在插入区间前面的区间
        //2.与插入区间重叠的区间，进行合并处理
        //3.在插入区间后面的区间
        //
        vector<vector<int>> ans;
        int n = intervals.size();
        bool flag = false;
        int start = newInterval[0], end = newInterval[1];
        int i = 0;
        while(i < n && intervals[i][1] < start){
            ans.push_back(intervals[i]);
            ++i;
        }
        while(i < n && intervals[i][0] <= end){
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            ++i;
        }
        ans.push_back({start,end});
        while(i < n){
            ans.push_back(intervals[i]);
            ++i;
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
// @lc code=start
struct cmp{
    bool operator()(pair<int,int> &a,pair<int,int> &b){
        return a.second<b.second;
    }
};
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> que;
        vector<int> bounds;
        for(vector<int> &item:buildings){
            bounds.push_back(item[0]);
            bounds.push_back(item[1]);
        }
        sort(bounds.begin(),bounds.end());

        vector<vector<int>> res;
        int n=buildings.size(),i=0;
        for(int &bound:bounds){
            while(i<n&&buildings[i][0]<=bound){
                que.push(make_pair(buildings[i][1],buildings[i][2]));
                ++i;
            }
            while(!que.empty()&&que.top().first<=bound){
                que.pop();
            }
            int maxn=que.empty()?0:que.top().second;
            if(res.size()==0||maxn!=res.back()[1]){
                res.push_back({bound,maxn});
            }
        }
        return res;
    }
};
// @lc code=end


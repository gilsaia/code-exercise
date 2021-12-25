/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */
#include<vector>
#include<queue>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> count(numCourses,0);
        vector<int> path[numCourses];
        for(vector<int> &item:prerequisites){
            path[item[1]].push_back(item[0]);
            ++count[item[0]];
        }
        vector<int> res;
        queue<int> que;
        for(int i=0;i<numCourses;++i){
            if(count[i]==0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int tmp=que.front();
            que.pop();
            res.push_back(tmp);
            for(int &i:path[tmp]){
                --count[i];
                if(count[i]==0){
                    que.push(i);
                }
            }
        }
        if(res.size()==numCourses){
            return res;
        }
        res.clear();
        return res;
    }
};
// @lc code=end


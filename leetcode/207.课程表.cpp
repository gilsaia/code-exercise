/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include<vector>
#include<queue>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> count(numCourses,0);
        vector<int> path[numCourses];
        for(vector<int> &item:prerequisites){
            path[item[1]].push_back(item[0]);
            ++count[item[0]];
        }
        int clear=0;
        queue<int> que;
        for(int i=0;i<numCourses;++i){
            if(count[i]==0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int tmp=que.front();
            que.pop();
            ++clear;
            for(int &i:path[tmp]){
                --count[i];
                if(count[i]==0){
                    que.push(i);
                }
            }
        }
        if(clear==numCourses){
            return true;
        }
        return false;
    }
};
// @lc code=end


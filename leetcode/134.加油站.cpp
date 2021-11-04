/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int i=0;
        while(i<n){
            int sgas=0,scost=0;
            int cnt=0;
            while(cnt<n){
                int j=(i+cnt)%n;
                sgas+=gas[j];
                scost+=cost[j];
                if(sgas<scost){
                    break;
                }
                ++cnt;
            }
            if(cnt==n){
                return i;
            }
            i=i+cnt+1;
        }
        return -1;
    }
};
// @lc code=end


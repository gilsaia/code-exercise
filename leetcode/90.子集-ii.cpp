/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    void dfs(map<int,int> &count,vector<vector<int>> &res,vector<int> &cur){
        if(count.empty()){
            res.push_back(cur);
            return;
        }
        auto iter=count.begin();
        int element=iter->first,curcount=iter->second;
        count.erase(iter);
        dfs(count,res,cur);
        for(int i=0;i<curcount;++i){
            cur.insert(cur.end(),i+1,element);
            dfs(count,res,cur);
            cur.erase(cur.end()-(i+1),cur.end());
        }
        count[element]=curcount;
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int,int> count;
        for(int element:nums){
            count[element]++;
        }
        vector<vector<int>> res;
        vector<int> cur;
        dfs(count,res,cur);
        return res;
    }
};
// @lc code=end


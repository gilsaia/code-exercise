/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    void recur(vector<vector<int>> &res,int &n,int &k,vector<int> &cur,int ind){
        if(cur.size()==k){
            res.push_back(cur);
            return;
        }
        for(int i=ind;i<=n;++i){
            cur.push_back(i);
            recur(res,n,k,cur,i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        recur(res,n,k,cur,1);
        return res;
    }
};
// @lc code=end


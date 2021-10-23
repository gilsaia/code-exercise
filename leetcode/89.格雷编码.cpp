/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
// @lc code=start
class Solution2 {
public:
    bool dfs(vector<int> &res,bool used[],int x,int &n){
        res.push_back(x);
        if(res.size()==(1<<n)){
            return true;
        }
        for(int i=0;i<n;++i){
            int next=x^(1<<i);
            if(!used[next]){
                used[next]=true;
                bool dfsres=dfs(res,used,next,n);
                if(dfsres){
                    return true;
                }
                used[next]=false;
            }
        }
        res.pop_back();
        return false;
    }
    vector<int> grayCode(int n) {
        bool *used=new bool[1<<n];
        memset(used,0,sizeof(bool)*(1<<n));
        vector<int> res;
        used[0]=true;
        dfs(res,used,0,n);
        return res;
    }
};
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        int head=1;
        for(int i=0;i<n;++i){
            for(int j=(1<<i)-1;j>=0;--j){
                res.push_back(head+res[j]);
            }
            head<<=1;
        }
        return res;
    }
};
// @lc code=end


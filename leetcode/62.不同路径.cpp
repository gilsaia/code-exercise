/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long low=m+n-2,up=min(n-1,m-1);
        long long res=1;
        for(long long i=0;i<up;++i){
            res*=(low-i);
        }
        for(long long tmp=2;tmp<=up;++tmp){
            res/=tmp;
        }
        int ans=res;
        return ans;
    }
};
// @lc code=end


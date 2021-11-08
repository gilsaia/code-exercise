/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2){
            return n;
        }
        int ans=0;
        for(int i=0;i<n;++i){
            if(ans>=(n-i)||ans>n/2){
                break;
            }
            unordered_map<int,int> hash;
            for(int j=i+1;j<n;++j){
                int x=points[i][0]-points[j][0];
                int y=points[i][1]-points[j][1];
                if(!x){
                    y=1;
                }else if(!y){
                    x=1;
                }else{
                    int gc=gcd(x,y);
                    x/=gc,y/=gc;
                    if(y<0){
                        x*=-1,y*=-1;
                    }
                }
                hash[y+x*20001]++;
            }
            for(auto &iter:hash){
                ans=max(ans,iter.second+1);
            }
        }
        return ans;
    }
};
// @lc code=end


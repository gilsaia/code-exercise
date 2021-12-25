/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */
#include<cstring>
using namespace std;
// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        int prime[5000020];
        memset(prime,0,sizeof(prime));
        int res=0;
        for(int i=2;i<n;++i){
            if(prime[i]==0){
                ++res;
                for(int j=i*2;j<n;j+=i){
                    prime[j]=1;
                }
            }
        }
        return res;
    }
};
// @lc code=end


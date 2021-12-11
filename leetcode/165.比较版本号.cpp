/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1=0,v2=0;
        int ind1=0,ind2=0;
        while(ind1<version1.size()&&ind2<version2.size()){
            while(ind1<version1.size()&&version1[ind1]!='.'){
                v1*=10;
                v1+=version1[ind1]-'0';
                ++ind1;
            }
            ++ind1;
            while(ind2<version2.size()&&version2[ind2]!='.'){
                v2*=10;
                v2+=version2[ind2]-'0';
                ++ind2;
            }
            ++ind2;
            if(v1>v2){
                return 1;
            }else if(v1<v2){
                return -1;
            }
            v1=0;
            v2=0;
        }
        while(ind1<version1.size()){
            while(ind1<version1.size()&&version1[ind1]!='.'){
                v1*=10;
                v1+=version1[ind1]-'0';
                ++ind1;
            }
            ++ind1;
            if(v1!=0){
                return 1;
            }
        }
        while(ind2<version2.size()){
            while(ind2<version2.size()&&version2[ind2]!='.'){
                v2*=10;
                v2+=version2[ind2]-'0';
                ++ind2;
            }
            ++ind2;
            if(v2!=0){
                return -1;
            }
        }
        return 0;
    }
};
// @lc code=end


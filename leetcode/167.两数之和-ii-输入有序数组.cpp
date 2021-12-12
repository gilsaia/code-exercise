/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution2 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size();++i){
            int cur=numbers[i];
            int l=i+1,r=numbers.size();
            while(l<r){
                int mid=(l+r)/2;
                if((cur+numbers[mid])==target){
                    return vector<int>{i+1,mid+1};
                }
                if((cur+numbers[mid])>target){
                    r=mid;
                }else{
                    l=mid+1;
                }
            }
        }
        return vector<int>{0,0};
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        while(l<r){
            if((numbers[l]+numbers[r])==target){
                return vector<int>{l+1,r+1};
            }
            if((numbers[l]+numbers[r])>target){
                --r;
            }else{
                ++l;
            }
        }
        return vector<int>{0,0};
    }
};
// @lc code=end


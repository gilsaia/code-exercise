/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int item=nums[0],count=0;
        for(int element:nums){
            if(element==item){
                ++count;
            }else{
                if(count==0){
                    item=element;
                    count=1;
                }else{
                    --count;
                }
            }
        }
        return item;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int ind=digits.size()-1;
        while(ind>=0){
            digits[ind]++;
            if(digits[ind]<10){
                break;
            }
            if(ind!=0){
                digits[ind]=0;
            }
            --ind;
        }
        if(digits[0]>=10){
            digits[0]=0;
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
// @lc code=end


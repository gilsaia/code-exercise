/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    static bool cmp(int a,int b){
        int ia=0,ib=0;
        while(a||b){
            ia=a%10;
            ib=b%10;
            if(ia>ib){
                return true;
            }else if(ia<ib){
                return false;
            }
            a/=10;
            b/=10;
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
            long sx = 10, sy = 10;
            while (sx <= x) {
                sx *= 10;
            }
            while (sy <= y) {
                sy *= 10;
            }
            return sy * x + y > sx * y + x;
        });
        if (nums[0] == 0) {
            return "0";
        }
        string ret;
        for (int &x : nums) {
            ret += to_string(x);
        }
        return ret;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int insert=m+n-1;
        --m,--n;
        while(m>=0&&n>=0){
            if(nums1[m]>nums2[n]){
                nums1[insert]=nums1[m];
                --m;
                --insert;
            }else{
                nums1[insert]=nums2[n];
                --n;
                --insert;
            }
        }
        while(n>=0){
            nums1[insert]=nums2[n];
            --n;
            --insert;
        }
    }
};
// @lc code=end


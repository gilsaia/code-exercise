/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int maxl=(1<<nums.size());
        vector<vector<int>> res;
        for(int i=0;i<maxl;++i){
            vector<int> find;
            int tmp=i;
            int ind=0;
            while(tmp){
                if(tmp&1){
                    find.push_back(nums[ind]);
                }
                tmp>>=1;
                ++ind;
            }
            res.push_back(find);
        }
        return res;
    }
};
// @lc code=end


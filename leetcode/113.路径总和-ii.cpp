/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(vector<vector<int>> &res,vector<int> &ans,TreeNode *root,int target){
        ans.push_back(root->val);
        if(root->val==target&&!root->left&&!root->right){
            res.push_back(ans);
            ans.pop_back();
            return;
        }
        if(root->left){
            dfs(res,ans,root->left,target-root->val);
        }
        if(root->right){
            dfs(res,ans,root->right,target-root->val);
        }
        ans.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> ans;
        if(!root){
            return res;
        }
        dfs(res,ans,root,targetSum);
        return res;
    }
};
// @lc code=end


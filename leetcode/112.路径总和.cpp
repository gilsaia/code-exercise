/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        queue<pair<TreeNode *,int>> que;
        que.push(make_pair(root,root->val));
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;++i){
                pair<TreeNode *,int> tmp=que.front();
                que.pop();
                if(tmp.second==targetSum&&!tmp.first->left&&!tmp.first->right){
                    return true;
                }
                if(tmp.first->left){
                    que.push(make_pair(tmp.first->left,tmp.second+tmp.first->left->val));
                }
                if(tmp.first->right){
                    que.push(make_pair(tmp.first->right,tmp.second+tmp.first->right->val));
                }
            }
        }
        return false;
    }
};
// @lc code=end


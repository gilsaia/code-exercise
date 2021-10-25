/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        queue<TreeNode *> *cur=new queue<TreeNode *>,*next=new queue<TreeNode *>;
        next->push(root);
        vector<int> ans;
        while(!next->empty()){
            ans.clear();
            swap(cur,next);
            while(!cur->empty()){
                TreeNode *tmp=cur->front();
                cur->pop();
                ans.push_back(tmp->val);
                if(tmp->left){
                    next->push(tmp->left);
                }
                if(tmp->right){
                    next->push(tmp->right);
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
class Solution2 {
public:
    bool check(TreeNode *left,TreeNode *right){
        if(left==nullptr&&right==nullptr){
            return true;
        }
        if(left==nullptr||right==nullptr){
            return false;
        }
        if(left->val!=right->val){
            return false;
        }
        bool res=true;
        res&=check(left->left,right->right);
        res&=check(left->right,right->left);
        return res;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return check(root->left,root->right);
    }
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        queue<TreeNode *> que;
        que.push(root);
        que.push(root);
        while(!que.empty()){
            TreeNode *a=que.front();
            que.pop();
            TreeNode *b=que.front();
            que.pop();
            if(!a&&!b){
                continue;
            }
            if((!a||!b)||(a->val!=b->val)){
                return false;
            }
            que.push(a->left);
            que.push(b->right);
            que.push(a->right);
            que.push(b->left);
        }
        return true;
    }
};
// @lc code=end


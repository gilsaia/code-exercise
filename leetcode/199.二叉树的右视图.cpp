/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root){
            return res;
        }
        queue<TreeNode *> que;
        que.push(root);
        int size=1;
        while(size){
            int tmp=size;
            size=0;
            if(tmp){
                --tmp;
                TreeNode *top=que.front();
                que.pop();
                res.push_back(top->val);
                if(top->right){
                    que.push(top->right);
                    ++size;
                }
                if(top->left){
                    que.push(top->left);
                    ++size;
                }
            }
            while(tmp){
                --tmp;
                TreeNode *cur=que.front();
                que.pop();
                if(cur->right){
                    que.push(cur->right);
                    ++size;
                }
                if(cur->left){
                    que.push(cur->left);
                    ++size;
                }
            }
        }
        return res;
    }
};
// @lc code=end


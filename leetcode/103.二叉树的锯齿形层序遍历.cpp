/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        stack<TreeNode *> *sta=new stack<TreeNode *>,*next=new stack<TreeNode *>;
        vector<int> ans;
        next->push(root);
        int hei=1;
        while(!next->empty()){
            swap(next,sta);
            ans.clear();
            while(!sta->empty()){
                TreeNode *tmp=sta->top();
                sta->pop();
                ans.push_back(tmp->val);
                if(hei&1){
                    if(tmp->left){
                        next->push(tmp->left);
                    }
                    if(tmp->right){
                        next->push(tmp->right);
                    }
                }else{
                    if(tmp->right){
                        next->push(tmp->right);
                    }
                    if(tmp->left){
                        next->push(tmp->left);
                    }
                }
            }
            ++hei;
            res.push_back(ans);
        }
        return res;
    }
};
// @lc code=end


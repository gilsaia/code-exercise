/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */
#include<vector>
#include<algorithm>
#include<stack>
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
    void recoverTree(TreeNode* root) {
        stack<TreeNode *> sta;
        TreeNode *x=nullptr,*y=nullptr;
        TreeNode *pred=nullptr;
        while(!sta.empty()||root!=nullptr){
            while (root!=nullptr){
                sta.push(root);
                root=root->left;
            }
            root=sta.top();
            sta.pop();
            if(pred!=nullptr&&root->val<pred->val){
                y=root;
                if(x==nullptr){
                    x=pred;
                }else{
                    break;
                }
            }
            pred=root;
            root=root->right;
        }
        swap(x->val,y->val);
    }
};
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *x=nullptr,*y=nullptr,*pred=nullptr,*predecessor=nullptr;
        while(root!=nullptr){
            if(root->left!=nullptr){
                predecessor=root->left;
                while(predecessor->right!=nullptr&&predecessor->right!=root){
                    predecessor=predecessor->right;
                }
                if(predecessor->right==nullptr){
                    predecessor->right=root;
                    root=root->left;
                }else{
                    if(pred!=nullptr&&root->val<pred->val){
                        y=root;
                        if(x==nullptr){
                            x=pred;
                        }
                    }
                    pred=root;

                    predecessor->right=nullptr;
                    root=root->right;
                }
            }else{
                if(pred!=nullptr&&root->val<pred->val){
                    y=root;
                    if(x==nullptr){
                        x=pred;
                    }
                }
                pred=root;
                root=root->right;
            }
        }
        swap(x->val,y->val);
    }
};
// @lc code=end


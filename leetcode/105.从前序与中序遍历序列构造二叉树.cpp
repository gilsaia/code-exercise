/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *dfs(vector<int> &preorder,vector<int> &inorder,int l,int r,int ind){
        TreeNode *root=new TreeNode(preorder[ind]);
        if((r-l)==1){
            return root;
        }
        int val=preorder[ind];
        int pos=find(inorder.begin()+l,inorder.begin()+r,val)-inorder.begin();
        if(pos>l){
            root->left=dfs(preorder,inorder,l,pos,ind+1);
        }
        if((pos+1)<r){
            int newind=ind+pos-l+1;
            root->right=dfs(preorder,inorder,pos+1,r,newind);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder,inorder,0,preorder.size(),0);
    }
};
// @lc code=end


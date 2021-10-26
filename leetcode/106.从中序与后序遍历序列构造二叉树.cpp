/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode *dfs(vector<int> &inorder,vector<int> &postorder,int l,int r,int ind){
        TreeNode *root=new TreeNode(postorder[ind]);
        if((r-l)==1){
            return root;
        }
        int val=postorder[ind];
        int pos=find(inorder.begin()+l,inorder.begin()+r,val)-inorder.begin();
        if(pos>l){
            int newind=ind-(r-pos);
            root->left=dfs(inorder,postorder,l,pos,newind);
        }
        if((pos+1)<r){
            root->right=dfs(inorder,postorder,pos+1,r,ind-1);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder,postorder,0,inorder.size(),inorder.size()-1);
    }
};
// @lc code=end


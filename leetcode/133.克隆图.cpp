/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        unordered_map<int,Node *> hash;
        Node *root=new Node(node->val);
        hash[root->val]=root;
        queue<Node *>que;
        que.push(node);
        que.push(root);
        while(!que.empty()){
            Node *toclo=que.front();
            que.pop();
            Node *clo=que.front();
            que.pop();
            for(Node *cur:toclo->neighbors){
                if(!hash.count(cur->val)){
                    hash[cur->val]=new Node(cur->val);
                    que.push(cur);
                    que.push(hash[cur->val]);
                }
                clo->neighbors.push_back(hash[cur->val]);
            }
        }
        return root;
    }
};
// @lc code=end


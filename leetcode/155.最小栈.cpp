/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include<stack>
using namespace std;
// @lc code=start
struct Node{
    int val;
    Node *next;
};
class MinStack {
    Node *minEle;
    stack<Node *> sta;
public:
    MinStack() {
        minEle=nullptr;
    }
    
    void push(int val) {
        if(minEle&&minEle->val<val){
            Node *tmp=new Node();
            tmp->val=val;
            tmp->next=nullptr;
            sta.push(tmp);
        }else{
            Node *tmp=new Node();
            tmp->val=val;
            tmp->next=minEle;
            minEle=tmp;
            sta.push(tmp);
        }
    }
    
    void pop() {
        Node *tmp=sta.top();
        if(tmp==minEle){
            minEle=tmp->next;
        }
        sta.pop();
    }
    
    int top() {
        Node *tmp=sta.top();
        return tmp->val;
    }
    
    int getMin() {
        if(minEle){
            return minEle->val;
        }
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end


/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||k==0||head->next==nullptr){
            return head;
        }
        int count=1;
        ListNode *cur=head;
        while(cur->next!=nullptr){
            ++count;
            cur=cur->next;
        }
        k=count-k%count;
        if(k==count){
            return head;
        }
        cur->next=head;
        while(k--){
            cur=cur->next;
        }
        ListNode *newhead=cur->next;
        cur->next=nullptr;
        return newhead;
    }
};
// @lc code=end


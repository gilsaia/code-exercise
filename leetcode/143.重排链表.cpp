/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */
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
    void reorderList(ListNode* head) {
        int n=0;
        ListNode *cur=head;
        while(cur){
            ++n;
            cur=cur->next;
        }
        if(n<3){
            return;
        }
        cur=head->next;
        ListNode *tmp=cur->next,*last=head;
        last->next=nullptr;
        for(int i=0;i<((n-1)/2);++i){
            cur->next=last;
            last=cur;
            cur=tmp;
            tmp=cur->next;
        }
        ListNode *lefttmp,*righttmp;
        if(n%2){
            lefttmp=last->next;
            last->next=nullptr;
            righttmp=cur->next;
            cur->next=last;
            last=lefttmp;
            lefttmp=last->next;
            last->next=cur;
        }else{
            righttmp=cur->next;
            cur->next=nullptr;
            lefttmp=last->next;
            last->next=cur;
        }
        while(lefttmp){
            cur=righttmp;
            righttmp=cur->next;
            cur->next=last;
            last=lefttmp;
            lefttmp=last->next;
            last->next=cur;
        }
        return;
    }
};
// @lc code=end


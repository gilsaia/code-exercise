/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *fake=new ListNode(0,head);
        int ind=0;
        ListNode *leftbefore,*cur=fake,*leftpoi,*lefthead;
        while(cur){
            if(ind==(left-1)){
                leftbefore=cur;
            }
            if(ind==left){
                leftpoi=cur;
                lefthead=cur;
            }
            if(ind==right){
                leftbefore->next=cur;
                lefthead->next=cur->next;
            }
            if(ind>left&&ind<=right){
                ListNode *tmp=cur->next;
                cur->next=leftpoi;
                leftpoi=cur;
                cur=tmp;
            }else{
                cur=cur->next;
            }
            ++ind;
        }
        return fake->next;
    }
};
// @lc code=end


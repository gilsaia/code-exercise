/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
class Solution2 {
public:
    //offical
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }
        ListNode* dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            while (curr != nullptr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummyHead->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        int length=0;
        ListNode *cur=head;
        while(cur){
            ++length;
            cur=cur->next;
        }
        cur=head;
        ListNode *dummy=new ListNode(0,head);
        for(int i=1;i<length;i*=2){
            ListNode *first=dummy->next,*last=dummy;
            while(first){
                ListNode *head1=first;
                for(int j=1;j<i&&first->next;++j){
                    first=first->next;
                }
                ListNode *head2=first->next;
                first->next=nullptr;
                first=head2;
                for(int j=1;j<i&&first&&first->next;++j){
                    first=first->next;
                }
                ListNode *next=nullptr;
                if(first){
                    next=first->next;
                    first->next=nullptr;
                }
                ListNode *merged=merge(head1,head2);
                last->next=merged;
                while(last->next){
                    last=last->next;
                }
                first=next;
            }
        }
        return dummy->next;
    }
    ListNode* merge(ListNode *a,ListNode *b){
        ListNode *dummy=new ListNode(0);
        ListNode *cur=dummy;
        while(a&&b){
            if(a->val<b->val){
                cur->next=a;
                a=a->next;
                cur=cur->next;
            }else{
                cur->next=b;
                b=b->next;
                cur=cur->next;
            }
        }
        if(a){
            cur->next=a;
        }else{
            cur->next=b;
        }
        return dummy->next;
    }
};
// @lc code=end


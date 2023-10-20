/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
  */

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
    void reverse(ListNode *s,ListNode*e){
        ListNode*p=s->next,*q=s,*r=NULL;
        while(r!=e){
            q->next = r;
            r=q;
            q=p;
            if(p) p=p->next;
        }  
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode *prev = NULL,*ans=NULL,*e=head;
        int i=0;
        while(e){
            i++;
            ListNode*s=head;
            if(i%k==0){
                head = e->next;
                reverse(s,e);
                if(prev) prev->next = e;
                if(!ans) ans = e;
                prev = s;
                prev->next = head;
                e = head;
            }
            else e=e->next;
        }
        return ans;
    }
};

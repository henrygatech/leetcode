/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *g=new ListNode(x-1);
        g->next=head;
        head=g;
        
        ListNode *pre, *p=head;
        while(p && p->val<x){
            pre=p;
            p=p->next;
        }
        
        if(p){
            ListNode *cur=pre;
            while(p){
                if(p->val<x){
                    ListNode *temp=cur->next;
                    pre->next=p->next;
                    cur->next=p;
                    cur=p;
                    p->next=temp;
                    p=pre;
                }
                pre=p;
                p=p->next;
            }
        }
        
        head=g->next;
        delete g;
        return head;
    }
};

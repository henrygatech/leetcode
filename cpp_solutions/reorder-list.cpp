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
    ListNode *reverse(ListNode *head){
        ListNode *pre=NULL, *cur=head;
        while(cur){
            ListNode *temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        return pre;
    }

    void reorderList(ListNode *head) {
        if(!head || !head->next || !head->next->next) return;
        
        ListNode *slow=head, *fast=head, *tail=NULL;
        while(fast && fast->next){
            tail=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast) // if there are odd # of nodes
            tail=tail->next;
        
        ListNode *shead=reverse(tail->next);
        tail->next=NULL;
        
        ListNode *cur=head, *scur=shead;
        while(scur){
            ListNode *t1=cur->next, *t2=scur->next;
            cur->next=scur;
            scur->next=t1;
            cur=t1;
            scur=t2;
        }
    }
};

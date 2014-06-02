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
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || k==0) return head;
        ListNode *p1=head, *p2=head;
        for(int i=0;i<k;i++){
            if(p1->next) p1=p1->next;
            else p1=head;
        }
        if(p1==head) return head;
        
        while(p1->next!=NULL){
            p1=p1->next;
            p2=p2->next;
        }
        
        p1->next=head;
        head=p2->next;
        p2->next=NULL;
        return head;
    }
};

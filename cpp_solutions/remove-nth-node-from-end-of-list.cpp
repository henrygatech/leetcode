
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p1=head, *p2=head, *pre=NULL;
        while(n>1){
            p1=p1->next;
            n--;
        }
        
        while(p1->next!=NULL){
            pre=p2;
            p1=p1->next;
            p2=p2->next;
        }
        
        if(pre==NULL){
            delete head;
            return p2->next;
        }
        else{
            pre->next=p2->next;
            delete p2;
            return head;
        }
        
    }
};

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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next || !head->next->next) return NULL;
        
        ListNode *p1=head->next, *p2=head->next->next;
        while(p1!=p2){
            if(!p2->next || !p2->next->next)
                return NULL;
            p1=p1->next;
            p2=p2->next->next;
        }
        p2=head;
        while(p1!=p2){
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};

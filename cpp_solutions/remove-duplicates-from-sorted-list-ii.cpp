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
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return head;
        ListNode *g=new ListNode(-1);
        g->next=head;
        head=g;
        ListNode *pre=head;
        
        while(pre->next && pre->next->next){
            if(pre->next->val == pre->next->next->val){
                int val=pre->next->val;
                while(pre->next && pre->next->val==val){
                    ListNode *temp=pre->next;
                    pre->next=pre->next->next;
                    delete temp;
                }
            }
            else{
                pre=pre->next;
            }
        }

        head=g->next;
        delete g;
        return head;
    }
};

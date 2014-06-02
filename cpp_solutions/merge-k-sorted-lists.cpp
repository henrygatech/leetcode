
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(lists.size()==0) return NULL;
        int cursize = lists.size();
        while(cursize>1){
            int halfsize = (cursize+1)/2;
            for(int i=0; i<halfsize&&i+halfsize<cursize; i++){
                ListNode *l1 = lists[i];
                ListNode *l2 = lists[i+halfsize];
                ListNode *result = merge2Lists(l1,l2);
                lists[i] = result;
            }
            cursize = halfsize;
        }
        return lists[0];
    }
    
    ListNode *merge2Lists(ListNode *l1, ListNode *l2){
        ListNode *result = NULL;
        ListNode *current = NULL;
        if(l1==NULL&&l2==NULL) return NULL;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        if(l1->val<l2->val){
            result = l1;
            l1 = l1->next;
        }
        else{
            result = l2;
            l2 = l2->next;
        }

        current = result;
        while(l1&&l2){
            if(l1->val<l2->val){
                current->next = l1;
                current = current->next;
                l1 = l1->next;
            }
            else{
                current->next = l2;
                current = current->next;
                l2 = l2->next;
            }
        }
        
        if(l1==NULL){
            current->next = l2;
        }
        
        if(l2==NULL){
            current->next = l1;
        }
        
        return result;
    }
};

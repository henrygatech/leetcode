/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        unordered_map<RandomListNode *, RandomListNode *> m;
        RandomListNode *cur=head, *copy=new RandomListNode(head->label);
        m[head]=copy;
        while(cur){
            RandomListNode *randn=cur->random;
            if(randn){
                if(m.find(randn)==m.end()){
                    RandomListNode *temp=new RandomListNode(randn->label);
                    m[randn]=temp;
                    m[cur]->random=temp;
                }
                else{
                    m[cur]->random=m[randn];
                }
            }
            
            RandomListNode *nextn=cur->next;
            if(nextn){
                if(m.find(nextn)==m.end()){
                    RandomListNode *temp=new RandomListNode(nextn->label);
                    m[nextn]=temp;
                    m[cur]->next=temp;
                }
                else{
                    m[cur]->next=m[nextn];
                }
            }
            cur=cur->next;
        }
        
        return copy;
    }
};

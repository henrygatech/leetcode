/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!node) return NULL;
        queue<UndirectedGraphNode *> q;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        q.push(node);
        UndirectedGraphNode * graphcopy=new UndirectedGraphNode(node->label);
        map[node]=graphcopy;
        
        while(!q.empty()){
            UndirectedGraphNode *cur=q.front();
            q.pop();
            int n=cur->neighbors.size();
            for(int i=0;i<n;i++){
                UndirectedGraphNode *neighbor=cur->neighbors[i];
                if(map.find(neighbor)==map.end()){
                    map[neighbor]=new UndirectedGraphNode(neighbor->label);
                    q.push(neighbor);
                }
                map[cur]->neighbors.push_back(map[neighbor]);
            }
        }
        
        return graphcopy;
        
    }
};

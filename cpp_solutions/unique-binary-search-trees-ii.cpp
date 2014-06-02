/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return gen(1,n);
    }
    
    vector<TreeNode *> gen(int start, int end){
        vector<TreeNode *> subtree;
        if(start>end){
            subtree.push_back(NULL);
            return subtree;
        }
        
        for(int i=start;i<=end;i++){
            vector<TreeNode *> lefttree=gen(start,i-1);
            vector<TreeNode *> righttree=gen(i+1,end);
            for(int j=0;j<lefttree.size();j++){
                for(int k=0;k<righttree.size();k++){
                    TreeNode *node=new TreeNode(i);
                    node->left=lefttree[j];
                    node->right=righttree[k];
                    subtree.push_back(node);
                }
            }
        }
        return subtree;
    }
};

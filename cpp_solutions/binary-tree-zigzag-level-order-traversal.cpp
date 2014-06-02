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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(!root) return result;
        vector<int> line;
        stack<TreeNode *> s1, s2;
        bool ltor=true;
        s1.push(root);
        while(!s1.empty()){
            while(!s1.empty()){
                TreeNode *node=s1.top();
                s1.pop();
                line.push_back(node->val);
                if(ltor){
                    if(node->left) s2.push(node->left);
                    if(node->right) s2.push(node->right);
                }
                else{
                    if(node->right) s2.push(node->right);
                    if(node->left) s2.push(node->left);
                }
            }
            ltor=!ltor;
            result.push_back(line);
            line.clear();
            swap(s1,s2);
        }
        return result;
    }
};

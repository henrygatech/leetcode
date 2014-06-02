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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if(!root) return result;
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *pre=NULL;
        while(!s.empty()){
            TreeNode *cur=s.top();
            if(!pre || pre->left==cur || pre->right==cur){
                if(cur->left) s.push(cur->left);
                else if(cur->right) s.push(cur->right);
                else{
                    result.push_back(cur->val);
                    s.pop();
                }
            }
            else if(cur->left==pre){
                if(cur->right) s.push(cur->right);
                else{
                    result.push_back(cur->val);
                    s.pop();
                }
            }
            else{
                result.push_back(cur->val);
                s.pop();
            }
            pre=cur;
        }
        return result;
    }
};

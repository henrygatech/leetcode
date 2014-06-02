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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if(!root) return result;
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *cur;
        
        while(!s.empty()){
            cur=s.top();
            s.pop();
            result.push_back(cur->val);
            if(cur->right) s.push(cur->right);
            if(cur->left) s.push(cur->left);
        }
        
        return result;
    }
};

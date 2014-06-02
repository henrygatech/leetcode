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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        if(!root) return result;
        vector<int> line;
        queue<TreeNode *> q1,q2;
        q1.push(root);
        while(!q1.empty()){
            while(!q1.empty()){
                TreeNode *node=q1.front();
                q1.pop();
                line.push_back(node->val);
                if(node->left) q2.push(node->left);
                if(node->right) q2.push(node->right);
            }
            swap(q1,q2);
            result.push_back(line);
            line.clear();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

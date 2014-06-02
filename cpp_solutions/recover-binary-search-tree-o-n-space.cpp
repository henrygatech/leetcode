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
    void recoverTree(TreeNode *root) {
        vector<TreeNode *> list;
        vector<int> vals;
        inorder(root,list,vals);
        sort(vals.begin(),vals.end());
        for(int i=0;i<vals.size();i++)
            list[i]->val=vals[i];
    }
    
    void inorder(TreeNode *node, vector<TreeNode *> &list, vector<int> &vals){
        if(!node) return;
        inorder(node->left, list, vals);
        list.push_back(node);
        vals.push_back(node->val);
        inorder(node->right, list, vals);
    }
};

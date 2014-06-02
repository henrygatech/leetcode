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
        TreeNode *cur, *pre, *f1=NULL, *f2=NULL, *parent=NULL;
        if(!root) return;
        bool found=false;
        cur=root;
        while(cur){
            if(!cur->left){
                if(parent && parent->val>cur->val){
                    if(!found){
                        f1=parent;
                        found=true;
                    }
                    f2=cur;
                }
                parent=cur;
                cur=cur->right;
            }
            else{
                pre=cur->left;
                while(pre->right && pre->right!=cur)
                    pre=pre->right;
                if(pre->right==NULL){
                    pre->right=cur;
                    cur=cur->left;
                }
                else{
                    pre->right=NULL;
                    if(parent && parent->val>cur->val){
                        if(!found){
                            f1=parent;
                            found=true;
                        }
                        f2=cur;
                    }
                    parent=cur;
                    cur=cur->right;
                }
            }
        }
        if(f1 && f2) swap(f1->val,f2->val);
    }
};

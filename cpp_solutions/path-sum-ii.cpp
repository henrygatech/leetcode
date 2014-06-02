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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> sol;
        find(root,sum,result,sol);
        return result;
    }
    
    void find(TreeNode *node, int sum, vector<vector<int> > &result, vector<int> &sol){
        if(!node) return;
        sum -= node->val;
        if(!node->left && !node->right){
            if(sum==0){
                sol.push_back(node->val);
                result.push_back(sol);
                sol.pop_back();
            }
            return;
        }
        sol.push_back(node->val);
        find(node->left,sum,result,sol);
        find(node->right,sum,result,sol);
        sol.pop_back();
    }
};

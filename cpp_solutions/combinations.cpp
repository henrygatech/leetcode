class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> sol;
        comb(result,sol,n,k,1);
        return result;
    }
    
    void comb(vector<vector<int> > &result, vector<int> &sol, int n, int k, int start){
        if(sol.size()==k){
            result.push_back(sol);
            return;
        }
        for(int i=start;i<=n;i++){
            sol.push_back(i);
            comb(result,sol,n,k,i+1);
            sol.pop_back();
        }
    }
};

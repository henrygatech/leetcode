class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        vector<int> sol;
        sort(S.begin(),S.end());
        sub(result,sol,S,0);
        return result;
    }
    
    void sub(vector<vector<int> > &result, vector<int> &sol, vector<int> &S, int start){
        result.push_back(sol);
        if(sol.size()==S.size()) return;
        for(int i=start;i<S.size();i++){
            sol.push_back(S[i]);
            sub(result,sol,S,i+1);
            sol.pop_back();
        }
    }
};

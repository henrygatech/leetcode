class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        vector<int> sol;
        int n=num.size();
        vector<int> visited(n,0);
        perm(result,sol,num,visited);
        return result;
    }
    
    void perm(vector<vector<int> > &result, vector<int> &sol, vector<int> &num, vector<int> &visited){
        if(sol.size()==num.size()){
            result.push_back(sol);
            return;
        }
        for(int i=0;i<num.size();i++){
            if(visited[i]==0){
                visited[i]=1;
                sol.push_back(num[i]);
                perm(result,sol,num,visited);
                sol.pop_back();
                visited[i]=0;
            }
        }
    }
    
};

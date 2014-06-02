class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        vector<int> sol;
        vector<int> visited(num.size(),0);
        sort(num.begin(),num.end());
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
                while(i<num.size()-1 && num[i]==num[i+1]) i++;
            }
        }
    }
};

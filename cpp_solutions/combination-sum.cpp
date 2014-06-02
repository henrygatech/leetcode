class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ret;
        vector<int> sol;
        sort(candidates.begin(),candidates.end());
        int sum=0;
        comb(ret,sol,candidates,sum,target,0);
        return ret;
    }
    
    void comb(vector<vector<int> > &ret, vector<int> &sol, vector<int> &num, int &sum, int target, int start){
        if(sum>target) return;
        if(sum==target){
            ret.push_back(sol);
            return;
        }
        for(int i=start;i<num.size();i++){
            sum+=num[i];
            sol.push_back(num[i]);
            comb(ret,sol,num,sum,target,i);
            sol.pop_back();
            sum-=num[i];
        }
    }
};

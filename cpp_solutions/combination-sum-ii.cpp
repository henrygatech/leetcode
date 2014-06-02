class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ret;
        vector<int> sol;
        sort(num.begin(),num.end());
        int sum=0;
        comb(ret,sol,num,sum,target,0);
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
            comb(ret,sol,num,sum,target,i+1);
            sol.pop_back();
            sum-=num[i];
            while(i<num.size()-1 && num[i+1]==num[i]) i++;
        }
    }
};

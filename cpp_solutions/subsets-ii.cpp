class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> result;
        vector<int> sol;
        sort(S.begin(),S.end());
        sub(result,sol,S,0);
        return result;
    }
    void sub(vector<vector<int>> &result, vector<int> &sol, vector<int> &s, int start){
        result.push_back(sol);
        for(int i=start;i<s.size();i++){
            sol.push_back(s[i]);
            sub(result,sol,s,i+1);
            sol.pop_back();
            while(i<s.size()-1 && s[i]==s[i+1]) i++;
        }
    }
};

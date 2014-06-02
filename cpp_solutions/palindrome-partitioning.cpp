class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > result;
        vector<string> sol;
        par(result,sol,s,0);
        return result;
    }
    
    void par(vector<vector<string>> &result, vector<string> &sol, string &s, int start){
        if(start==s.size()){
            result.push_back(sol);
            return;
        }
        
        for(int i=start;i<s.size();i++){
            if(valid(s,start,i)){
                sol.push_back(s.substr(start,i-start+1));
                par(result,sol,s,i+1);
                sol.pop_back();
            }
        }
    }
    
    bool valid(string s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};

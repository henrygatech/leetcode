class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        string sol;
        vector<string> result;
        int n=s.size();
        vector<bool> possible(n+1,true);
        getallsol(0,s,dict,result,sol,possible);
        return result;
    }
    
    void getallsol(int start, string &s, unordered_set<string> &dict, vector<string> &result, string &sol, vector<bool> &possible){
        if(start==s.size()){
            result.push_back(sol.substr(0,sol.size()-1));
            return;
        }
        for(int i=start;i<s.size();i++){
            string piece=s.substr(start,i-start+1);
            if(dict.count(piece)>0 && possible[i+1]){
                sol=sol+piece+' ';
                int beforechange=result.size();
                getallsol(i+1,s,dict,result,sol,possible);
                if(result.size()==beforechange)
                    possible[i+1]=false;
                sol.resize(sol.size()-1-piece.size());
            }
        }
    }
};

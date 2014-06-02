
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> letters;
        if(digits.empty()){
            letters.push_back("");
            return letters;
        }
        
        map<char, string> m;
        m['0']="";
        m['1']="";
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        
        string sol;
        comb<char, string>(letters,sol,digits,m,0);
        return letters;
    }
    
    template<class T, class S>
    void comb(vector<string> &letters, string &sol, string &digits, map<T, S> &m, int cur){

        if(cur==digits.size()){
            letters.push_back(sol);
            return;
        }
        for(int i=0;i<m[digits[cur]].size();i++){
            sol+=m[digits[cur]][i];
            comb(letters,sol,digits,m,cur+1);
            sol.resize(sol.size()-1);
        }
    }
};

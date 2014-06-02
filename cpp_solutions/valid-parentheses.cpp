
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                sta.push(s[i]);
            else if(!sta.empty() && valid(sta.top(),s[i]))
                sta.pop();
            else
                return false;
        }
        return sta.empty();
    }
    
    bool valid(char c1, char c2){
        return c1=='(' && c2==')' || c1=='[' && c2==']' || c1=='{' && c2=='}';
    }
};

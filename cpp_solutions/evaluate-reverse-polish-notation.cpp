class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        unordered_set<string> operators={"+","-","*","/"};
        for(int i=0;i<tokens.size();i++){
            if(operators.count(tokens[i])==0){
                s.push(stoi(tokens[i]));
            }
            else{
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                if(tokens[i]=="+")  s.push(b+a);
                else if(tokens[i]=="-") s.push(b-a);
                else if(tokens[i]=="*") s.push(b*a);
                else s.push(b/a);
            }
        }
        return s.top();
    }
};
